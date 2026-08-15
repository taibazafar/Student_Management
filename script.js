let students =
    JSON.parse(localStorage.getItem("students")) || [];


const studentId =
    document.getElementById("studentId");

const studentName =
    document.getElementById("studentName");

const studentAge =
    document.getElementById("studentAge");

const studentDepartment =
    document.getElementById("studentDepartment");

const addButton =
    document.getElementById("addButton");

const studentList =
    document.getElementById("studentList");

const searchId =
    document.getElementById("searchId");

const searchButton =
    document.getElementById("searchButton");

const searchResult =
    document.getElementById("searchResult");


function saveStudents() {

    localStorage.setItem(
        "students",
        JSON.stringify(students)
    );
}


function displayStudents() {

    studentList.innerHTML = "";

    if (students.length === 0) {

        studentList.innerHTML =
            "<p>No students available.</p>";

        return;
    }


    students.forEach(function(student) {

        const div =
            document.createElement("div");

        div.className = "student";


        div.innerHTML = `

            <div class="student-info">

                <strong>
                    ${student.name}
                </strong>

                <br>

                ID: ${student.id}

                <br>

                Age: ${student.age}

                <br>

                Department:
                ${student.department}

            </div>

            <button
                class="delete"
                onclick="deleteStudent(${student.id})">

                Delete

            </button>

        `;


        studentList.appendChild(div);

    });
}


function addStudent() {

    const id =
        Number(studentId.value);

    const name =
        studentName.value.trim();

    const age =
        Number(studentAge.value);

    const department =
        studentDepartment.value.trim();


    if (
        !id ||
        !name ||
        !age ||
        !department
    ) {

        alert(
            "Please fill all fields."
        );

        return;
    }


    const exists =
        students.some(
            student => student.id === id
        );


    if (exists) {

        alert(
            "Student ID already exists."
        );

        return;
    }


    students.push({
        id: id,
        name: name,
        age: age,
        department: department
    });


    saveStudents();

    displayStudents();


    studentId.value = "";

    studentName.value = "";

    studentAge.value = "";

    studentDepartment.value = "";
}


function deleteStudent(id) {

    students =
        students.filter(
            student => student.id !== id
        );


    saveStudents();

    displayStudents();
}


function searchStudent() {

    const id =
        Number(searchId.value);


    const student =
        students.find(
            student => student.id === id
        );


    if (!student) {

        searchResult.innerHTML =
            "<p>Student not found!</p>";

        return;
    }


    searchResult.innerHTML = `

        <div class="student">

            <div class="student-info">

                <strong>Student Found!</strong>

                <br>

                ID: ${student.id}

                <br>

                Name: ${student.name}

                <br>

                Age: ${student.age}

                <br>

                Department:
                ${student.department}

            </div>

        </div>
    `;
}


addButton.addEventListener(
    "click",
    addStudent
);


searchButton.addEventListener(
    "click",
    searchStudent
);


displayStudents();