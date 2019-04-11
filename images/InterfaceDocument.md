##Login Api 测试环境
-----------------
BaseURL:http://192.168.0.202/sys4/S2S/master/web/

- 请求URL:

```
http://192.168.0.202/sys4/S2S/master/web/login
```

- 请求方式：

```
 POST
```

- 参数说明

| 请求参数 | 参数类型|参数说明|
|--------|--------|-------|
| username | string |用户名|
| password | string |用户密码|


- 返回说明:

| 返回参数 | 参数类型|参数说明|
|--------|--------|-------|
| code | int |返回状态码: 200成功，非200 失败|
| message | string |提示信息|
| token | string |token信息|
| roleType | int |用户类型1:管理员 2:运营 其他:不可以进行登录|
| username | string |用户昵称|

- 返回示例

```
{
  "code": 200,
  "message": "登录成功",
  "token": "eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiIsImp0aSI6IjRmMWcyM2ExMmFhIn0.eyJpc3MiOiJodHRwOlwvXC93aXNlbWVkaWEuY29tIiwiYXVkIjoiaHR0cDpcL1wvd2lzZW1lZGlhLmNvbSIsImp0aSI6IjRmMWcyM2ExMmFhIiwiaWF0IjoxNTU0Mjg2MDQ4LCJleHAiOjE1NTY4NzgwNDgsInVpZCI6IjI3MzEiLCJ1c2VyVHlwZSI6IjEifQ.yhUd4qZIZIlLarC9ooVWfP6ZumekoxrFu1RsCvjPtpw",
  "data": {
    "roleType": "1",
    "username": "admin"
  }
}
```


##User-List Api 测试环境
-----------------
BaseURL:http://192.168.0.202/sys4/S2S/master/web/

- 请求URL:

```
http://192.168.56.10/S2S/web/user/list
```

- 请求方式：

```
GET
```

- 参数说明

请求参数: 无


- 返回说明:

| 返回参数 | 参数类型|参数说明|
|--------|--------|-------|
| code | int |返回状态码: 200成功，非200 失败|
| message | string |提示信息|
| data | json |数据信息|
| user_id | int |用户id|
| user_name | int |用户昵称|
- 返回示例

```
{
  "code": 200,
  "message": "获取用户列表信息成功",
  "data": {
    "list": [
      {
        "user_id": "1",
        "user_name": "admin"
      },
      {
        "user_id": "2",
        "user_name": "ooop"
      },
      {
        "user_id": "3",
        "user_name": "test_cgl"
      },
      
    ]
  }
}
```

##给用户分配角色信息 /user/manage/role 测试环境
-----------------
BaseURL:http://192.168.0.202/sys4/S2S/master/web/

- 请求URL:

```
http://192.168.0.202/sys4/S2S/master/web/user/manage/role
```

- 请求方式：

```
 POST
```

- 参数说明

| 请求参数 | 参数类型|参数说明|
|--------|--------|-------|
| roleType | int |1：管理员,2:运营|


- 请求实例

```
{
    "roleType":1
}
```

- 返回说明:

| 返回参数 | 参数类型|参数说明|
|--------|--------|-------|
| code | int |返回状态码: 200成功，非200 失败|
| message | string |提示信息|
| data | json |返回数据信息|


- 返回示例

```
{
    "code": 200,
    "message": "写入用户角色信息成功",
    "data": []
}
```
