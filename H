<!DOCTYPE html>
<html>
<head>
  <title>All Tasks (1–13)</title>
  <style>
    body { font-family: Arial; padding: 20px; }
    input, button, textarea { margin-top: 6px; padding: 8px; width: 300px; }
    section { border: 1px solid #ccc; padding: 15px; margin: 15px 0; }
  </style>
</head>
<body>
  <h1>All Tasks (1–13)</h1>

  <section>
    <h3>Task 1: Get All Books</h3>
    <button onclick="showBooks()">Get All Books</button>
    <ul id="task1"></ul>
  </section>

  <section>
    <h3>Task 2: Get Book by ISBN</h3>
    <input id="isbn2" placeholder="ISBN"><button onclick="getBookByISBN()">Search</button>
    <div id="task2"></div>
  </section>

  <section>
    <h3>Task 3: Get Books by Author</h3>
    <input id="author3"><button onclick="searchByAuthor()">Search</button>
    <ul id="task3"></ul>
  </section>

  <section>
    <h3>Task 4: Get Books by Title</h3>
    <input id="title4"><button onclick="searchByTitle()">Search</button>
    <ul id="task4"></ul>
  </section>

  <section>
    <h3>Task 5: Get Book Review</h3>
    <input id="title5"><button onclick="getReview()">Get Review</button>
    <div id="task5"></div>
  </section>

  <section>
    <h3>Task 6: Register New User</h3>
    <input id="regUser" placeholder="Username">
    <input id="regEmail" placeholder="Email">
    <input id="regPass" placeholder="Password"><br>
    <button onclick="register()">Register</button>
    <div id="task6"></div>
  </section>

  <section>
    <h3>Task 7: Login</h3>
    <input id="loginUser" placeholder="Username">
    <input id="loginPass" placeholder="Password"><br>
    <button onclick="login()">Login</button>
    <div id="task7"></div>
  </section>

  <section>
    <h3>Task 8: Add/Modify Review</h3>
    <input id="title8" placeholder="Book Title">
    <textarea id="review8" placeholder="Your review"></textarea>
    <button onclick="addReview()">Submit</button>
    <div id="task8"></div>
  </section>

  <section>
    <h3>Task 9: Delete Book Review</h3>
    <input id="delTitle9" placeholder="Book Title">
    <button onclick="deleteReview()">Delete</button>
    <div id="task9"></div>
  </section>

  <section>
    <h3>Task 10: Get All Books (Async Callback)</h3>
    <button onclick="getBooksAsync(displayBooks)">Fetch Books</button>
    <ul id="task10"></ul>
  </section>

  <section>
    <h3>Task 11: Search by ISBN (Promise)</h3>
    <input id="isbn11" placeholder="ISBN">
    <button onclick="searchISBN()">Search</button>
    <div id="task11"></div>
  </section>

  <section>
    <h3>Task 12: Search by Author</h3>
    <input id="author12">
    <button onclick="searchAuthor12()">Search</button>
    <ul id="task12"></ul>
  </section>

  <section>
    <h3>Task 13: Search by Title</h3>
    <input id="title13">
    <button onclick="searchTitle13()">Search</button>
    <ul id="task13"></ul>
  </section>

<script>
const books = [
  { title: "1984", author: "George Orwell", isbn: "9781", review: "Classic dystopia" },
  { title: "Animal Farm", author: "George Orwell", isbn: "9782", review: "Satirical tale" },
  { title: "Moby-Dick", author: "Herman Melville", isbn: "9783", review: "Whaling epic" }
];

function showBooks() {
  const ul = document.getElementById("task1"); ul.innerHTML = "";
  books.forEach(b => ul.innerHTML += `<li>${b.title}</li>`);
}

function getBookByISBN() {
  const isbn = document.getElementById("isbn2").value;
  const b = books.find(x => x.isbn === isbn);
  document.getElementById("task2").textContent = b ? `${b.title} by ${b.author}` : "Not found";
}

function searchByAuthor() {
  const author = document.getElementById("author3").value.toLowerCase();
  const ul = document.getElementById("task3"); ul.innerHTML = "";
  books.filter(b => b.author.toLowerCase() === author).forEach(b => ul.innerHTML += `<li>${b.title}</li>`);
}

function searchByTitle() {
  const title = document.getElementById("title4").value.toLowerCase();
  const ul = document.getElementById("task4"); ul.innerHTML = "";
  books.filter(b => b.title.toLowerCase().includes(title)).forEach(b => ul.innerHTML += `<li>${b.title}</li>`);
}

function getReview() {
  const title = document.getElementById("title5").value;
  const b = books.find(b => b.title === title);
  document.getElementById("task5").textContent = b ? b.review : "No review";
}

function register() {
  const u = document.getElementById("regUser").value;
  const e = document.getElementById("regEmail").value;
  const p = document.getElementById("regPass").value;
  document.getElementById("task6").textContent = u && e && p ? `Registered: ${u}` : "All fields required";
}

function login() {
  const u = document.getElementById("loginUser").value;
  const p = document.getElementById("loginPass").value;
  document.getElementById("task7").textContent = (u === "janani" && p === "12345") ? "Login success" : "Invalid";
}

function addReview() {
  const title = document.getElementById("title8").value;
  const review = document.getElementById("review8").value;
  const b = books.find(b => b.title === title);
  if (b) b.review = review;
  else books.push({ title, author: "Unknown", isbn: "", review });
  document.getElementById("task8").textContent = "Review added/updated";
}

function deleteReview() {
  const title = document.getElementById("delTitle9").value;
  const i = books.findIndex(b => b.title === title);
  if (i >= 0) { books.splice(i, 1); document.getElementById("task9").textContent = "Deleted"; }
  else document.getElementById("task9").textContent = "Not found";
}

function getBooksAsync(cb) {
  setTimeout(() => cb(books.map(b => b.title)), 1000);
}
function displayBooks(list) {
  const ul = document.getElementById("task10"); ul.innerHTML = "";
  list.forEach(b => ul.innerHTML += `<li>${b}</li>`);
}

function searchISBN() {
  const isbn = document.getElementById("isbn11").value;
  new Promise((res, rej) => {
    const b = books.find(x => x.isbn === isbn);
    setTimeout(() => b ? res(b.title) : rej("Not found"), 500);
  })
  .then(txt => document.getElementById("task11").textContent = txt)
  .catch(e => document.getElementById("task11").textContent = e);
}

function searchAuthor12() {
  const author = document.getElementById("author12").value.toLowerCase();
  const ul = document.getElementById("task12"); ul.innerHTML = "";
  books.filter(b => b.author.toLowerCase() === author).forEach(b => ul.innerHTML += `<li>${b.title}</li>`);
}

function searchTitle13() {
  const title = document.getElementById("title13").value.toLowerCase();
  const ul = document.getElementById("task13"); ul.innerHTML = "";
  books.filter(b => b.title.toLowerCase().includes(title)).forEach(b => ul.innerHTML += `<li>${b.title}</li>`);
}
</script>
</body>
</html>
