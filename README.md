# 함수 설명
- Buffer_size가 어떤 값이든 한 줄씩 출력하는 함수

```c
 int get_next_line(int fd, char **line);
```
<br/>

# 아이디어
1. static char *arr[fd](포인터 배열)에 읽어온(read) 값을 계속 넣어준다.

  - arr[fd] == NULL 이면 새로 만들어 준다.
  - ex) 4개씩 넣어주기 arr[fd]의 값 : aaab -> aaabbbc -> aaabbb'\n' -> NULL('\n'이 있기 때문) .....

2. '\n'이 있는 경우는 

   - 처음 ~ '\n' 전까지 => 출력할 line에 저장 
   -  '\n' 다음 부터 끝까지 => arr[fd]에 다시 넣어주기 
   + '\n'만 있는 경우는 EOF랑 헷갈 릴 수 있기 때문에 check를 넣어서 관리해줍니다.

<br/>

# 주의
- static 함수를 이용하여 Buffer_size가 상관없게 한다.
- 맨 마지막 EOF인 곳은 arr[fd] = NULL로 해줘야 segment fault가 나지 않는다. 
