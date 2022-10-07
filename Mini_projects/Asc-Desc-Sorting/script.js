const courses = [
    {
        name: "Complete Java Course",
        price: "5.1"
    },
    {
        name: "Complete C++ Course",
        price: "3.5"
    },
    {
        name: "Complete SEO Course",
        price: "8.99"
    },
    {
        name: "Flutter Crash Course",
        price: "2.5"
    },
    {
        name: "Freelancing Crash Course",
        price: "2.2"
    },
];



function generateList() {
    const ul = document.querySelector(".list-group");
    ul.innerHTML = "";

    courses.forEach((courses) => {
        const li = document.createElement("li");
        li.classList.add("list-group-item");

        const name = document.createTextNode(courses.name);
        li.appendChild(name);

        const span = document.createElement("span");
        span.classList.add("float-end");
        const price = document.createTextNode(courses.price);
        span.appendChild(price);

        li.appendChild(span);
        ul.appendChild(li);
    });
}

generateList();

const buttonAsc = document.querySelector(".btn-success");
const buttonDes = document.querySelector(".btn-primary");

buttonAsc.addEventListener("click", () => {
    courses.sort((a,b) => a.price - b.price);
    generateList();
});

buttonDes.addEventListener("click", () => {
    courses.sort((a,b) => b.price - a.price);
    generateList();
});