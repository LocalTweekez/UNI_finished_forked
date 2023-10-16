
"use strict";

var baseURL = "https://api.sr.se/api/v2/";
let audio;
//
// Wait for DOM to load
document.addEventListener("DOMContentLoaded", function(){ 
    //
    // Read SR channels and dynamically create list of channels
    let url = baseURL + "channels?size=100&format=json";
    fetch(url, {method: 'GET'})
        .then(response => response.text())
            .then(data => {
                var jsonData = JSON.parse( data );
                for(var i=0; i < jsonData.channels.length; i++){
                   document.getElementById("mainnavlist").innerHTML += "<li id='"+
                   jsonData.channels[i].id+"'>"+
                   "<img src="+ jsonData.channels[i].image + " alt='logo' style='width:1.5rem'>" +
                   jsonData.channels[i].name+"</li>";

                   document.getElementById("searchProgram").innerHTML += "<option value='"+
                   jsonData.channels[i].id+"'>"+
                   jsonData.channels[i].name+"</option>";      
                }
            })
            .catch(error => {
                alert('There was an error '+error);
            });

    //
    // Create eventlistener for click on search program
    document.getElementById('searchbutton').addEventListener("click", function(e){
       
        var channelid = document.getElementById("searchProgram").value;
        document.getElementById("info").innerHTML = "";

        fetch(`${baseURL}scheduledepisodes?channelid=${channelid}&format=json`)
            .then(response => response.text())
            .then(data => {
                var jsonData = JSON.parse(data);
                for (var i = 0; i < jsonData.schedule.length; i++) {
                    const start = new Date(parseInt(jsonData.schedule[i].starttimeutc.substr(6)));
                    const { title, description} = jsonData.schedule[i];
                    document.getElementById("info").innerHTML += `<h1>${title}</h1><h3> ${description}  </h3><p> ${start}  </p><hr>`;

                }
            })
            .catch(error => {
                alert('There was an error ' + error);
            });
    }) 

    //
    // Create eventlistener for clicks on dynamically created list of channels in mainnavlist
    document.getElementById('mainnavlist').addEventListener("click", function(e){

        var channelid = e.target.id;
        let url = baseURL + "channels?size=100&format=json";
        fetch(url, { method: 'GET' })
            .then(response => response.text())
            .then(data => {
                var jsonData = JSON.parse(data);
                for (var i = 0; i < jsonData.channels.length; i++) {
                    if (jsonData.channels[i].id == channelid) {
                        const { name, tagline, siteurl, liveaudio } = jsonData.channels[i];
                        document.getElementById("info").innerHTML = "";
                        document.getElementById("searchProgram").value = channelid;

                        document.getElementById("info").innerHTML += `<h1>${name}</h1><p> ${tagline}  </p><a href="${siteurl}" target=$_blank>link</a><hr>`;
                        audio = new Audio(liveaudio.url);
                        audio.play();

                        fetch(`${baseURL}playlists/rightnow?channelid=${channelid}&format=json`).then(resp => resp.text())
                        .then(Data => {
                            var JsonData = JSON.parse(Data);
                            const { previoussong, nextsong } = JsonData.playlist;
                            const nextsongDesc = nextsong ? nextsong.description : 'N/A';

                            document.getElementById("info").innerHTML += `<p>Previoussong: ${previoussong.description}</p><p>Next: ${nextsongDesc}</p>`;
                        })
                
                    }
                }
            })
            .catch(error => {
                alert('There was an error ' + error);
            });
        
        
    })      

    document.getElementById('mainnavlist').addEventListener("click", function () {
        audio.src = "";
    })
    

})// End of DOM content loaded
