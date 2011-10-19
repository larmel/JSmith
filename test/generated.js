/*	JSmith	*/
var x = 1
(function foo() { return x++; })();
(function main(){ hash = foo(); print(hash); return 0; })();