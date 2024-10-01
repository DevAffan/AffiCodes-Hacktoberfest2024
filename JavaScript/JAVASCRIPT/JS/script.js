 let hellobtn = document.querySelector('button');  // stored in a variable that is let
 hellobtn.addEventListener('click',inputmsg);

 function inputmsg()   // function declare
 {
    // alert("Danger Zone! so dont be open!");
    let name= prompt('Enter Name of Student');
    hellobtn.textContent='Roll No. 1:' +name;
 }

//  Input from input side
