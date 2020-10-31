### Libft(make a 42(Forty-Two) library)

#### memset
+ memory의 주소에 접근 시, unsigned char 로 형변환 해주어야 한다.

#### memcpy & memccpy
+ const에 대한 내용 정리
	+ const char * == char const * : pointer가 가르키는 char형 변수의 값을 바꿀 수 없다.
	+ char * const : char형 변수를 가르키는 pointer를 바꿀 수 없다.
	+ const char const * : pointer가 가르키는 char형 변수의 값, char형 변수를 가르키는 pointer 모두를 바꿀 수 없다.
	+ **const void * src를 unsigned char * 변수에 복사하고 싶으면, 명시적 형변환이 필요하다. const void * 이 아니라면, 암시적 형변환이 이루어진다.**

+ memccpy
The memccpy() function copies bytes from string src to string dst. If the character c (as converted to an unsigned char) occurs in the string src, the copy stops and a pointer to the byte after the copy of c in the string dst	is returned. Otherwise, len bytes are copied, and a NULL pointer is	returned

#### memmove(memcpy와 비교해서)
+ 출처 : https://blog.naver.com/sharonichoya/220510332768
+ memmove는 overlap으로 인해 복사가 제대로 되지 않는 문제를 예방한다. 따라서 memcpy에 비해 안정적인 방법이다.
+ src가 dst보다 작은경우 뒤에서 복사하면 overlap을 막을 수 	있다.
+ src가 dst보다 큰 경우는 앞에서부터 복사하게 되면 	overlap이 발생하지 않는다.


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
