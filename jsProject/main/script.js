

//want opacity of photos to be based on how many likes the photo has



var feed  = new Instafeed({
	//only show popular images
	get: "popular", 
	//tagName: "phillisugly",
	//limit is number of pics visible
	limit: "32",
	clientId: "7ca8963fd1414b218beed9b04e2a5cca" //my client id
});

feed.run();


$('#submit').click(function(){
	var search_term ={
		q:'bowery'
	};
	search(search_term);

});

function search(search_term){
	console.log('searching for ');
	console.dir(search_term);

	$.ajax({
		url: 'https://api.twitter.com/1.1/search/tweets.json?' + $.param(search_term),
		dataType: 'jsonp',
		success: function(data){
			console.log(data);

			for(item in data['results']){
				$('#tweets').append(
					'<li>' + data['results'][item]['text'] + '</li>');
			}
		}

	});

}


//have the page refresh every couple of seconds
//displays new content keeps viewer engaged

var time = new Date().getTime();

     function refresh() {
         if(new Date().getTime() - time >= 10000) 
             window.location.reload(true);
         else 
             setTimeout(refresh, 1000);
     }

     setTimeout(refresh, 1000);


//load text from twitter
var loadText = function(){


}


//load images from instagram
var loadImages = function(){



}



var init = function(){
	loadImages();
	loadText();

}

$(document).ready(function(){
	init();
})