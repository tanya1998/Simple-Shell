External Commands implemented along with their options:-

1. ls :- Options: (-a),(-A)
	 Errors : Checks if the directory is present or not.
		: Checks if their are any files in the provided directory else gives prompt.
	 Assumptions : Any other options except -a and -A will be treated as directories.
	 Test Case : i) ls ii) ls Desktop iii) ls -a iv) ls -A v) ls -g(shows directory doesn't exist)
2. cat:- Options: (-n),(-b), Also allows multiple files input.
	 Errors : Checks if their are required number of parameters.
		: Checks if the file is present else gives error.
	 Assumptions : Any other options except -n and -b will be treated as files.
	 Test Case : i) ls 'filename' ii) ls 'file1' 'file2' iii) ls -n 'filename' iv) ls -b 'filename'
3. date:- Options: (-r),(-I)
	  Errors : Checks if the file is present in case of -r.
		 : Any other options except these two will generate error.
	  Assumptions : The format of file modified not same as that of bash.
		      : Only one file input allowed for -r incase more entered shows modified date of first filename.
	  Test Case : i) date ii) date -r 'filename' iii) date -I
4. mkdir:- Options: (-p),(-v)
	   Errors : Check if the directory has alreay been created
		  : Checks for no. of arguments if less shows error
	   Assumptions : The created directory will have default rights as 755
           Test Case : i) mkdir kkll ii) mkdir -v kkll iii) mkdir -p aa/bb/cc
5. rm :- Options: (-i),(-d)
	 Errors : In case of rm it will not be able to delete a directory
		: In case of -d command it will first check if directory is empty then delete
	 Assumptions : In case of -i it checks only the first letter of string if its y then it takes it to be as yes else No
	 Test Case : i) rm -d kkll ii) rm 'filenmae' iii) rm -d aa iv)rm aa

Internal Commands implemented are:-

1. exit :- Simple system call(No options)
2. cd   :- Types of cd implemented ---('..','.','-','~','/','directory name')
3. echo :- Options: (-n),(-E)
	   Errors : Doesnot print \ and ' as in echo
	   Test Case :i) echo tan\nraj ii) echo tan\\n '"jjh" kkkll' iii) echo -n tttt iv) echo -E kkjhh/n/t
4. pwd  :- Getcwd simple function call(No options)
5. history :- No options (Implemented BY Array)

