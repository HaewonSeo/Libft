## Libft
+ Make a 42(Forty-Two) library
+ Introduction
C programming can be very tedious when one doesn’t have access to those highly useful
standard functions. This project gives you the opportunity to re-write those functions,
understand them, and learn to use them. This library will help you for all your future C
projects.
Through this project, we also give you the opportunity to expand the list of functions
with your own. Take the time to expand your libft throughout the year.


### Makefile
+ GNU Make 강좌 <http://doc.kldp.org/KoreanDoc/html/GNU-Make/GNU-Make.html#toc8>

### Test **(Thanks for Contributors!)**
+ **libft-war-machine** :  <https://github.com/ska42/libft-war-machine>
	+ Libftest/srcs/variables/check_compilation.sh 에서 clang -> gcc로 변경 후 실행함.
	+ ft_memchr.c & ft_lstmap.c 의 test file에서 format error 있어서 수정 후 진행함.

-----------------------------------------------
### Part 1 - Libc functions
+ In this first part, you must re-code a set of the libc functions, as defined in their
man. Your functions will need to present the same prototype and behaviors as the originals.


#### ft_memset
+ memory의 주소에 접근 시, unsigned char 로 형변환 해주어야 한다. <https://kldp.org/node/75686>
+ byte 단위로 초기화한다. int형 배열을 초기화 할 때 주의해야 한다. <https://blog.naver.com/chogahui05/221484049429>, <https://minusi.tistory.com/entry/memset-%EC%82%AC%EC%9A%A9%EC%8B%9C-%EC%A3%BC%EC%9D%98%ED%95%A0-%EC%A0%90>

#### ft_memcpy & ft_memccpy
+ const에 대한 내용 정리
	+ const char * == char const * : pointer가 가르키는 char형 변수의 값을 바꿀 수 없다.
	+ char * const : char형 변수를 가르키는 pointer를 바꿀 수 없다.
	+ const char const * : pointer가 가르키는 char형 변수의 값, char형 변수를 가르키는 pointer 모두를 바꿀 수 없다.
	+ **const void * src를 unsigned char * 변수에 복사하고 싶으면, 명시적 형변환이 필요하다. const void * 이 아니라면, 암시적 형변환이 이루어진다.**

+ ft_memccpy
The memccpy() function copies bytes from string src to string dst. If the character c (as converted to an unsigned char) occurs in the string src, the copy stops and a pointer to the byte after the copy of c in the string dst	is returned. Otherwise, len bytes are copied, and a NULL pointer is	returned

#### ft_memmove(ft_memcpy와 비교해서)
+ len : 복사할 크기 (byte 단위)
+ <https://blog.naver.com/sharonichoya/220510332768>
+ memmove는 자기 자신의 내용을 자기 자신에게 덮어쓸 떄 overlap으로 인해 복사가 제대로 되지 않는 문제를 예방한다. 따라서 memcpy에 비해 안정적인 방법이다.
+ src가 dst보다 앞인 경우는 뒤에서 복사하면 overlap을 막을 수 있다.
+ src가 dst보다 뒤인 경우는 앞에서부터 복사하게 되면 	overlap이 발생하지 않는다.


#### ft_strlcpy & ft_strlcat (return value에 대해)
+ the strlcpy() and strlcat() functions return the total length of the string they tried to create. For strlcpy() that means the length of src. For strlcat() that means the initial length of dst plus the length of src.
<https://www.freebsd.org/cgi/man.cgi?query=strlcat&apropos=0&sektion=0&manpath=FreeBSD+12.2-RELEASE+and+Ports&arch=default&format=html>
+ The length of the string that strlcat tried to create is returned, whether or not strlcat could store it in dest. If all of src was concatenated to dst, the return value will be less than size.
If dest is not nul-terminated, then strlcat will consider dest to be size in length and return size plus the length of src. <http://www.delorie.com/djgpp/doc/libc/libc_762.html>
+ strlcpy은 복사할 공간이 충분할 경우, 필요한 크기를 return 한다.
+ **ft_strlcat**의 return value
	+ (1) dstsize < len_dst + 1 : dstsize + len_src
	+ (2) dstsize >= len_dst + 1: len_dst + len_src
	+ (1)의 경우는 catination 이후의 길이가 기존 dst의 length + 1('\0'자리)보다 작은 경우로, catination 하려 했는데, 기존의 dst에 src를 이어 붙일 수 없으므로, catination이 불가능하다. 이 경우 dst의 length를 dstsize로 간주하여 dstsizt + len_src를 return 한다.
	+ (2)의 경우에는 catination이후의 크기가 기존 dst의 length + 1('\0'자리)보다 크거나 같기 때문에, catination이 가능하다. 따라서 catination을 수행하고(같은 경우에는 기존 dst의 '\0'자리에 '\0'을 쓰는 꼴), len_dst + len_src를 return 한다.


#### ft_strncmp
+ The strncmp() function compares **not more than len characters.**
+ ```i < n - 1``` : n개의 문자가 모두 같은 경우, n+1의 비교 결과를 return하는 오류를 방지하기 위한 조건.


#### ft_calloc
+ size byte 크기의 변수를 number개 저장하는 메모리 공간을 할당하고, 모든 byte를 0으로 초기화 한다.(ft_bzero()를 이용함)
+ type casting은 불필요하다. : <https://stackoverflow.com/questions/605845/do-i-cast-the-result-of-malloc>


#### ft_atoi
+ 부호는 1개만 있는 경우만 고려. 2개 이상일 경우, 결과는 0.
+ 기본적으로 atoi는 int형 범위를 벗어나는 값에 대해 에러를 출력하지 않는다.(오버플로우를 핸들링하지 않는다.)
+ str의 길이가 20이 넘어가면, stdlib.h의 atoi()는 -1 또는 0을 return 한다.(테스트를 통해 알게된 사실)
	+ 0인 경우 : 부호 상관없이 0 return
	+ 음수인 경우 : -1 return
	+ 양수인 경우 :  0 return

#### ft_memchr
+ void * : <https://blog.naver.com/sharonichoya/220501081810>

------------------------------------
### Part 2 - Additional functions
+ In this second part, you must code a set of functions that are either not included in the
libc, or included in a different form. Some of these functions can be useful to write Part
1’s functions.

#### ft_strmapi.c
+ void (*p_func)(int) : 포인터 p_func의 자료형은 void (\*)(int)
+ 사용 예
	+ (*p_func)(15) : 원칙적인 표현
	+ p_func(15) : 허용되는 표현
+ 함수의 파라미터로 함수 포인터가 사용되었다고 해서 무조건 함수 포인터에 함수의 주소를 전달해야 하는 것은 아니다. NULL이 전달될 수 있다.
+ 함수 포인터 : <https://blog.naver.com/tipsware/221286052738>
+ 함수 포인터 변수에 함수의 주소를 대입하기 위해서는 &함수명 을 대입한다.
+ 그러나, 함수의 경우에는 함수의 이름 자체가 함수의 호출 주소가 되기 때문에 & 연산자를 사용하지 않고 함수명만 적어도 동일하게 동작한다.

#### ft_putchar_fd && ft_putstr_fd
+ fd (file descripter) : <https://12bme.tistory.com/211>
+ Predefined open file descriptors(저수준 파일 입출력)
	+ #include &lt;unistd.h&gt;
	+ 0 : standard input
	+ 1 : standard output
	+ 2 : standard error
	+ 3~ : new fd
+ Predefined open streams(고수준 파일 입출력)
	+ #include &lt;stdio.h&gt;
	+ FILE *stdin;
	+ FILE *stdout;
	+ FILE *stderr;
+ write()
	return 값이 -1인 경우 상세한 오류는 errno에 저장된다.

#### ft_putnbr_fd
+ Windox/Unix/Linux 자료형 크기 정리
+ long size
	+ Windows 32bit, 64bit : 4 byte
	+ Unix/Linux 32bit : 4 byte
	+ Unix/Linux 64bit : 8 byte
----------------------------------------------
### Bonus Part
+ Having functions to manipulate memory and strings is very useful, but you’ll soon
discover that having functions to manipulate lists is even more useful. You’ll use the following structure to represent the elements of your list.
+ make bonus will add the bonus functions to the libft.a library
+ Here is a description of the fields of the t_list struct:
	+ content : The data contained in the element. The void * allows to store any kind of data.
	+ next : The next element’s address or NULL if it’s the last element.

#### ft_lstmap
+ void (*f)(void *)
	+ return : void
	+ input : void *
+ void *(*f)(void *)
	+ return : void *
	+ input : void
+ 같은 함수 포인터인데, return 값이 다르다는 차이.
+ 참고 : <https://stackoverflow.com/questions/34548762/c-isnt-that-hard-void-f>
+ 함수의 자료형 해석 : <https://www.cdecl.org/>
+ input parameter로 void (*f)(void *) 받아온 경우 이 함수포인터를 사용하는 형태. 아래는 모두 함수포인터를 가르킨다.
	+ (*f) : 원칙적인 표현
	+ f : 허용되는 표현
