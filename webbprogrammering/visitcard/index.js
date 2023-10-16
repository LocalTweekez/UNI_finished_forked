"use strict";
//
// Wait for DOM to load
document.addEventListener("DOMContentLoaded", function(){ 

    document.getElementById("page2").style.display = "none"; // Hide div with name "page2"

    document.getElementById("print").addEventListener("click", function(){
        document.getElementById("page1").style.display = "none"; // Hide div with name "page1"
        document.getElementById("page2").style.display = "block"; // Show div with name "page2"
        cardStyle(); 
        // Move text from input field in page 1 to presenting area in page 2   
        
    });

    document.getElementById("change2").addEventListener("click", function(){
        document.getElementById("page1").style.display = "block";
        document.getElementById("page2").style.display = "none";
    });

    document.getElementById("reset").addEventListener("click", function(){
        const arr = document.getElementsByClassName("inputs");
        for(var i = 0; i < arr.length; i++){
            document.getElementsByClassName("inputs")[i].value = "";
        }

    })

    function cardStyle(){

        document.getElementById("page2").style.backgroundColor = document.getElementById("card-color").value;
        document.getElementById("page2").style.fontFamily = document.getElementById("font-type").value;
        document.getElementById("page2").style.color = document.getElementById("text-color").value;

        companyNameAndTitle.innerHTML = document.getElementById('title').value + " at " + document.getElementById('company').value;
        ownerName.innerHTML = document.getElementById('firstname').value +" " + document.getElementById('surname').value ;
        
        
        pnOutput.innerHTML = "✆  " + document.getElementById('phone-number').value;
        emailOutput.innerHTML = "✉ " + document.getElementById('e-mail').value;;
    }

})