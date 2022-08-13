# RSwCF

RubenSystems website creation framework. A C++ library which provides a declaritive interface for creating views:

![alt text](https://github.com/RubenSystems/RSwCF/blob/main/Images/example.png)

RSwCF makes it easy to generate HTML and CSS for a project that requires a website interface. It mimics the easy to use SwiftUI library. 


### Content 

Every HTML tag is a view in RSwCF. e.g 

	<h1> hello there </h1> 
	
becomes 
	
	view("h1", content("hello there"))
	
### Style

Styles are added using the style function. e.g: 

	<h1 style="color:pink;"> hello there </h1> 
		
is roughly equivalnt to 
	
	view("h1", content("hello there"))
	->style({"color", "pink"})
		

RSwCF groups all the styles into a single stylesheet per container view. 
