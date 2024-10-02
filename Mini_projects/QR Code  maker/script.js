let term = document.getElementById('searchWord');
let imageDiv = document.getElementById('imageShown');
let clickedBtn = document.getElementById('btn');
let qrimage = document.getElementById('qrimage');
let textInImageDiv = document.getElementById('heading')

clickedBtn.addEventListener('click', ()=>{
    let termValue   = term.value.trim();
    // console.log(termValue);
    if(termValue.length != 0){
    qrimage.src = `https://api.qrserver.com/v1/create-qr-code/?size=150x150&data=${termValue}`
    imageDiv.classList.add('show-img');
    
    }
    // else{
    //     // Display an error message
    //     console.log("else is running");
    //    textInImageDiv.innerText="please enter a valid value";
    //     imageDiv.classList.remove('show-img');
    // }
})