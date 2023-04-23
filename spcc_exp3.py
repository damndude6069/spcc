f = open("test.txt", "r")

def isKeyword(word):
	keywords = ["auto", "break", "case", "char", "const", "continue", "default","do", "double", "else", "enum","extern", "float", "for", "goto", "if", "int","long", "register", "return", "short", "signed","sizeof", "static","struct","switch", "typedef", "union", "unsigned", "void", "volatile", "while"]
	if word in keywords:
		return True
	else:
		return False

def isDelimiter(word):
	delimiter = ['(', ')', '{', '}', ';', ',']
	if word in delimiter:
		return True
	else:
		return False

def isOperator(word):
	operator = ['+', '-', '*', '/', '=', '%']
	if word in operator:
		return True
	else:
		return False

for line in f:
	for word in line.split():
		if isKeyword(word):
			print(word + " is a Keyword")
		elif isDelimiter(word):
			print(word + " is a delimiter")
		elif isOperator(word):
			print(word + " is an Operator")
		else:
			print(word + " is a Token")
f.close()
"""
Test file(test.txt):
int sum ( int a , int b ) {
int c ;
c = a + b ;
return c ;
}
"""