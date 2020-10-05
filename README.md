# 42

## memcpy & memmove
### 출처 : https://blog.naver.com/sharonichoya/220510332768
### memmove는 overlap으로 인해 복사가 제대로 되지 않는 문제를 예방한다.
### memcpy에 비해 안정적인 방법.
### src가 dst보다 작은경우 뒤에서 복사하면 overlap을 막을 수 있다.
### src가 dst보다 큰 경우는 앞에서부터 복사하게 되면 overlap이 발생하지 않는다.
