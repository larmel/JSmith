function A()
{	
    var b = 1 <= 1;
    this.bar = b;
}

foo = new A();
print(foo.bar);
print(" ");

if (typeof foo.bar == "boolean") {
    print("Boolean");
}else {
    print("Number");
}
