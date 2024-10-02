const GenerateMemeBtn=document.querySelector(".App .App-btn");
const MemeImage=document.querySelector(".App img");
const MemeTitle=document.querySelector(".App .meme-title");
const MemeAuthor=document.querySelector(".meme-author");


const updateDetails =(url,title,author) =>{
    MemeImage.setAttribute("src",url);
    MemeTitle.innerHTML=title;
    MemeAuthor.innerHTML=author;
}

const GenerateMeme =() =>{
    fetch("https://meme-api.com/gimme").then((Response)=>Response.json()).then(data =>{
        updateDetails(data.url,data.title,data.author)
    });
}


GenerateMemeBtn.addEventListener("click", GenerateMeme);