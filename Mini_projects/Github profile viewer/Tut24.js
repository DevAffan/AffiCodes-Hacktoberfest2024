
const btn = document.getElementById('btn');
const searchBarValue = document.getElementById('search-word');
const card = document.querySelector('.card');
btn.addEventListener('click',()=>{
let value = searchBarValue.value;
console.log(value);
const url = `https://api.github.com/users/${value}`;
let newData = new XMLHttpRequest();
newData.open("GET",url);
newData.onreadystatechange=()=>{

    // console.log(newData.readyState);
    /* 
    The XMLHttpRequest.readyState property returns the state an XMLHttpRequest client is in
    So basically there are 4 ready State that are  from 0 -4 and every state has its own meaning 
    0- client is created and open is not called 
    1- open is called 
    2- send has been called 
    3 - respone hold partial data 
    4 - operation is completed 
    */

   if(newData.readyState == 4){
    let data = JSON.parse(newData.responseText);
    console.log(data);
    console.log("about the github data ");
    console.log("image link");
    console.log(data.login);
    console.log(data?.avatar_url);
    console.log(data.url);
    console.log(data.html_url);
    console.log(data.name);
    console.log(data.bio);
    console.log(data.public_repos);
    console.log(data.followers);
    console.log(data.following);
    console.log(data.created_at);

    // now let's add the data to the card 
    card.innerHTML=`
    <div class="card-main">
        <div class="image">
        <img src='${data?.avatar_url}' alt="myphoto">
        </div>
        <div class="info">
           <h2 class="name"> <span>Name:</span> ${data.name} </h2>
           <h3 class="userName" ><span>UserName:</span> ${data.login}</h3>
           <div className="newBox">
           <h4 class="followers grid-cont"><span>followers:</span>${data.followers}</h4>
           <h4 class="following grid-cont"><span>following:</span>${data.following}</h4>
           <h4 class="total_Repo grid-cont"><span>public_repos:</span>${data.public_repos}</h4>
           </div>
           
           <h4 class="link"><span>link:</span>${data.html_url}</h4>
          

        </div>
    </div>
    
    `
   }
}
newData.send();
});
