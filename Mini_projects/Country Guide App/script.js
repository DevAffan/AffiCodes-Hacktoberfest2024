let btn= document.getElementById('Submit-btn');
const inputCountry=document.getElementById('country-name');
const resultCont=document.getElementById('result');
btn.addEventListener("click",()=>{
    let countryName=inputCountry.value; //spain
    let Url=`https://restcountries.com/v3.1/name/${countryName}`;

    async function getData(){
        let data = await fetch(Url);
        let value = await data.json();
        // console.log(value);
        console.log(value[0]);
        console.log(value[0]?.name?.common);
        console.log(value[0]?.capital[0]);
        console.log(value[0]?.continents[0]);
        console.log(value[0]?.flags?.svg);
        console.log(value[0]?.timezones[0]);
        console.log(value[0]?.population);
        console.log(value[0]?.currencies);
        console.log(value[0]?.area);
        console.log(value[0]?.maps?.googleMaps);

        resultCont.innerHTML=`
          <img src=${value[0]?.flags?.svg} class="flag-image" >
            <h2>${value[0]?.name?.common}</h2>
           <div id="wrapper"> 
            <div id="data-wrapper">
            <h4>continents:</h4>
           <span>${value[0]?.continents[0]}</span>
           </div>
           </div>
           <div id="wrapper"> 
           <div id="data-wrapper">
           <h4>capital:</h4>
           <span>${value[0]?.capital[0]}</span>
           </div>
           </div>
           <div id="wrapper"> 
           <div id="data-wrapper">
           <h4>timezone:</h4>
           <span>${value[0]?.timezones[0]}</span>
           </div>
           </div>
           <div id="wrapper"> 
           <div id="data-wrapper">
           <h4>population:</h4>
           <span>${value[0]?.population}</span>
           </div>
           </div>
           <div id="wrapper"> 
           <div id="data-wrapper">
           <h4>currencies:</h4>
           <span>${value[0]?.currencies[Object.keys(value[0]?.currencies)].name} - ${Object.keys(value[0]?.currencies)}</span>
           </div>
           </div>
           <div id="wrapper"> 
           <div id="data-wrapper">
           <h4>total area :</h4>
           <span>${value[0]?.area}</span>
           </div>
           </div>
           <div id="wrapper"> 
           <div id="data-wrapper">
           <h4>map link:</h4>
           <span>${value[0]?.maps?.googleMaps} </span>
           </div>
           </div>` 

    }
    getData();
    
})
        
       
   
    
       

  



