
    // var lat = results[0].geometry.location.lat();
    //  var long = results[0].geometry.location.lng();
        
var thisLocationID;
        
    function findLoc() {
      var address = (document.getElementById('my-address'));
      var autocomplete = new google.maps.places.Autocomplete(address);
      autocomplete.setTypes(['geocode']);
       google.maps.event.addListener(autocomplete, 'place_changed', function() {
          var place = autocomplete.getPlace();
          if (!place.geometry) {
               return;
          }
  
       var address = '';
       if (place.address_components) {
           address = [
              (place.address_components[0] && place.address_components[0].short_name || ''),
               (place.address_components[1] && place.address_components[1].short_name || ''),
               (place.address_components[2] && place.address_components[2].short_name || '')
               ].join(' ');
         }
    });
} //end of findLoc


function codeAddress() {
    geocoder = new google.maps.Geocoder();
    var address = document.getElementById("my-address").value;
    geocoder.geocode( { 'address': address}, function(results, status) {
      if (status == google.maps.GeocoderStatus.OK) {

     // alert("Latitude: "+results[0].geometry.location.lat());
      //alert("Longitude: "+results[0].geometry.location.lng());
      
      lat = results[0].geometry.location.lat();
      long = results[0].geometry.location.lng();
      
    console.log(lat);
    console.log(long);
    
      
      $.ajax({
  		  url : 'https://api.instagram.com/v1/locations/search?lat=' + lat+ '&lng=' + long + '&access_token=1410992284.7ca8963.f603e277548348f1bf0fa24082e376ca',//sends url
  		  dataType : 'jsonp', //asks for this data type, is it a meta data?
  		  type: 'GET',
  		  success : function(obj){ //if it works do this with the response
  			//get location ids put it in an array, then print the array of images
  			for (i=0; i<obj.data.length; i++) {
  			  
					thisLocationID = +obj.data[i].id;
          console.log(thisLocationID);
          
       var feed  = new Instafeed({
    	//only show tagged images
    	get: "location", 
    	//latitude: "lat",
    	//longitude: "long",
    	locationId: thisLocationID,
    	//tagName: nameinput,
    	//limit is number of pics visible
    	limit: "50",
    	//links to instagram page set to false, default is true
    	//links: "false",
    	//puts the most liked photos first
    	sortBy: "most-liked",
    	clientId: "7ca8963fd1414b218beed9b04e2a5cca" //my client id
    });
  		//	feed.reload();
  			feed.run();
  		
  		//to only show the images according to that location 
  			var div = document.getElementById('instafeed');
        while(div.firstChild){
       div.removeChild(div.firstChild);
        }
  		              //	loadLocation(response);
  			} // end of for loop
      //feed.run();
  	    } // end of for loop
      });//end of ajax
  

    
   // instaloc(lat, long);
      } 

      else {
        alert("You need to type in a location in the search box");
      }
      
      

    });
    

  }
google.maps.event.addDomListener(window, 'load', findLoc);


    


// var nameinput;

// // http://localhost/#access_token=1410992284.7ca8963.f603e277548348f1bf0fa24082e376ca



//   function myFunction() {
//       var nameinput = document.getElementById("my-address").value;
//       //alert(nameinput);
//       //console.log(nameinput.value);
  
//   // window.location.reload(true);



// var feed  = new Instafeed({
// 	//only show tagged images
// 	get: "tagged", 
// 	//locationId: 
// 	tagName: nameinput,
// 	//limit is number of pics visible
// 	limit: "50",
// 	//links to instagram page set to false, default is true
// 	//links: "false",
// 	//puts the most liked photos first
// 	sortBy: "most-liked",
// 	clientId: "7ca8963fd1414b218beed9b04e2a5cca" //my client id
// });

// feed.run();
// instaloc();

// $('#submit').click(function(){
// 	var search_term ={
// 		q:'bowery'
// 	};
// 	search(search_term);

// });

// // function instaloc(lat, long){
// // //https://api.instagram.com/v1/media/search?lat=50.85396&lng=4.34150&distance=2000&access_token=ACCESS-TOKEN
  
// //   console.log('lat is ' + lat);
// //   console.log('long is ' + long);

// // 	$.ajax({
// // 		url: 'https://api.instagram.com/v1/media/search?lat=' + lat +'&lng=' + long+ '&distance=2000&access_token=1410992284.7ca8963.f603e277548348f1bf0fa24082e376ca',
// // 		dataType: 'jsonp',
// // 		success: function(data){
// // 			console.log(data);

// // 		// 	for(item in data['results']){
// // 		// 		$('#tweets').append(
// // 		// 			'<li>' + data['results'][item]['text'] + '</li>');
// // 			}
// // 		}

// // 	});

// }




// //have the page refresh every couple of seconds
// //displays new content keeps viewer engaged

// // var time = new Date().getTime();

// //     function refresh() {
// //         if(new Date().getTime() - time >= 10000) 
// //             window.location.reload(true);
// //         else 
// //             setTimeout(refresh, 1000);
// //     }

// //     setTimeout(refresh, 1000);









// var init = function(){
// 	loadImages();
// 	loadText();

// }

// $(document).ready(function(){
// 	init();
// })