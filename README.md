# 함수 설명
- Buffer_size가 어떤 값이든 한 줄씩 출력하는 함수

```c
 int get_next_line(int fd, char **line);
```

# 주의
- static 함수를 이용하여 Buffer_size가 상관없게 한다.
- 맨 마지막 EOF인 곳은 arr[fd] = NULL로 해줘야 segment fault가 나지 않는다. 
