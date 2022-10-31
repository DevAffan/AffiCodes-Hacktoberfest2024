import React from 'react';
function App() {
  let currdate = new Date();
currdate = currdate.getHours();
let greeting = "";
const cssStyle = {};
   if(currdate >= 4 && currdate < 12){
    greeting = 'Good Morning';
    cssStyle.color = "green";
   }
   else if(currdate >= 12 && currdate < 17){
    greeting = 'Good Afternoon';
    cssStyle.color = "orange";
   }
   else if(currdate >= 17 && currdate < 21){
    greeting = 'Good Evening';
    cssStyle.color = "blue";
   }
   else{
    greeting = 'Good Night';
    cssStyle.color = "black";
   }
  return(
    <>
    <div><h1>Hello, champ!<span style={cssStyle}>{greeting}</span></h1>
    </div>
      
    </>
  );
}

export default App;
