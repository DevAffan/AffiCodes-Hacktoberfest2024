const url="https://api.dictionaryapi.dev/api/v2/entries/en/";
const result= document.getElementById("result");
const btn=document.getElementById('submit-btn');

btn.addEventListener(
    "click",
    ()=>{

        let inputWord=document.getElementById("word-search").value;
        console.log(inputWord);

        async  function getData(){
            let data= await fetch(`${url}${inputWord}`);
            let jsonData= await data.json();
            console.log(jsonData);
            console.log(jsonData[0].word);
            console.log(jsonData[0].meanings[0].partOfSpeech);
            console.log(jsonData[0].phonetics[0].text);
            console.log(jsonData[0].meanings[0].definitions[0].definition);
            console.log(jsonData[0].meanings[1].synonyms);
            console.log(jsonData[0].meanings[1].definitions[0].definition);
            console.log(jsonData[0].meanings[2].definitions[0].definition);
            result.innerHTML=`
            <div class="word">
             <h2>${jsonData[0].word}</h2>
            </div>
            
            <div class="details">
             <p>${jsonData[0].meanings[0].partOfSpeech}</p>
             <p>/${jsonData[0].phonetics[0].text}/</p>
            </div>
            <p className="defination">
            ${jsonData[0].meanings[0].definitions[0].definition}
            </p>
            <p className="synonyms">
            ${jsonData[0].meanings[1].synonyms}
            </p>
            <p class="word-meaning">
            ${jsonData[0].meanings[1].definitions[0].definition}
            </p>
            <p class="word-example">
            ${jsonData[0].meanings[2].definitions[0].definition} 
             </p>
            `;


        }
        getData();
        
        

    }
)







       
      

      



 

    

    



