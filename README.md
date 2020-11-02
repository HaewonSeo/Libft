### Libft : Make a 42(Forty-Two) library

#### memset
+ memory의 주소에 접근 시, unsigned char 로 형변환 해주어야 한다. <https://kldp.org/node/75686>
+ byte 단위로 초기화한다. int형 배열을 초기화 할 때 주의해야 한다. <https://blog.naver.com/chogahui05/221484049429>, <https://minusi.tistory.com/entry/memset-%EC%82%AC%EC%9A%A9%EC%8B%9C-%EC%A3%BC%EC%9D%98%ED%95%A0-%EC%A0%90>

#### memcpy & memccpy
+ const에 대한 내용 정리
	+ const char * == char const * : pointer가 가르키는 char형 변수의 값을 바꿀 수 없다.
	+ char * const : char형 변수를 가르키는 pointer를 바꿀 수 없다.
	+ const char const * : pointer가 가르키는 char형 변수의 값, char형 변수를 가르키는 pointer 모두를 바꿀 수 없다.
	+ **const void * src를 unsigned char * 변수에 복사하고 싶으면, 명시적 형변환이 필요하다. const void * 이 아니라면, 암시적 형변환이 이루어진다.**

+ memccpy
The memccpy() function copies bytes from string src to string dst. If the character c (as converted to an unsigned char) occurs in the string src, the copy stops and a pointer to the byte after the copy of c in the string dst	is returned. Otherwise, len bytes are copied, and a NULL pointer is	returned

#### memmove(memcpy와 비교해서)
+ len : 복사할 크기 (byte 단위)
+ <https://blog.naver.com/sharonichoya/220510332768>
+ memmove는 자기 자신의 내용을 자기 자신에게 덮어쓸 떄 overlap으로 인해 복사가 제대로 되지 않는 문제를 예방한다. 따라서 memcpy에 비해 안정적인 방법이다.
+ src가 dst보다 앞인 경우는 뒤에서 복사하면 overlap을 막을 수 있다.
+ src가 dst보다 뒤인 경우는 앞에서부터 복사하게 되면 	overlap이 발생하지 않는다.


#### strlcpy & strlcat (return value에 대해)
+ the strlcpy() and strlcat() functions return the total length of the string they tried to create. For strlcpy() that means the length of src. For strlcat() that means the initial length of dst plus the length of src.
<https://www.freebsd.org/cgi/man.cgi?query=strlcat&apropos=0&sektion=0&manpath=FreeBSD+12.2-RELEASE+and+Ports&arch=default&format=html>
+ The length of the string that strlcat tried to create is returned, whether or not strlcat could store it in dest. If all of src was concatenated to dst, the return value will be less than size.
If dest is not nul-terminated, then strlcat will consider dest to be size in length and return size plus the length of src. <http://www.delorie.com/djgpp/doc/libc/libc_762.html>
+ strlcpy은 복사할 공간이 충분할 경우, 필요한 크기를 return 한다.
+ strlcat의 return value
	+ (1) dstsize < len_dst : dst_size + len_src
	+ (2) dstsize >= len_dst : len_dst + len_src
	+ (1)의 경우는 catination 이후의 길이가 기존 dst의 length보다 작은 경우로, catination 성공여부에 상관없다. 이 경우 dst의 length를 dstsize로 간주한다.


#### strncmp
+ The strncmp() function compares **not more than len characters.**
+ ```i < n - 1``` : n개의 문자가 모두 같은 경우, n+1의 비교 결과를 return하는 오류를 방지하기 위한 조건.


#### calloc
+ size byte 크기의 변수를 number개 저장하는 메모리 공간을 할당하고, 모든 byte를 0으로 초기화 한다.(ft_bzero()를 이용함)
