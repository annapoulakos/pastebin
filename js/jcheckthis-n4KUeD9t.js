function myFunction( myPassedVariable ){
	// Inside functions, you can use any passed or locally scoped variables without issue:
	myPassedVariable = myPassedVariable + 2;

	return myPassedVariable;
}

var someVariable = 3;
function myFunction(){
	// Inside functions, you can use any parent-scoped variables.
	
	someVariable = someVariable + 1;
	return someVariable;
}

var myClass = {
	myVariable: 1,
	myFunc: function(){
		// Inside classes, you have to qualify variables within the object with the this operator:

		this.myVariable = this.myVariable + 1;

		return this.myVariable;
	},
	myOtherFunc: function(){
		// Inside classes, you can also use any parent-scope variables:

		someVariable = someVariable + 1;
		return someVariable;
	}
}