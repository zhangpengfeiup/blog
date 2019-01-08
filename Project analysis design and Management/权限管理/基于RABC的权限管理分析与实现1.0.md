RABC权限管理:
	https://blog.csdn.net/painsonline/article/details/7183613/

需求:
    v1.0: 
	根据用户的角色信息去判断用户是否有进入该页面的权限。一个用户可能有多个角色，用户的权限是所有角色的权限之和。
	角色信息：每一个角色有不同的权限信息。
	权限信息: 系统中，权限表现的形式是什么？对功能的操作，对上传文件的修改，菜单的访问，页面上的元素的显示，图片的显示。
都是权限的范围。

用户表:
create table user(
user_id int primary key auto_increment  comment '用户id',
user_name varchar(50) not null default '' comment '用户名',
user_passwd varchar(50) not null default '' comment '用户密码',
)engine=innodb default charset=utf8 comment '用户表';

角色表	
	create table role (
		role_id int auto_increment primary key comment '角色id',
		role_name varchar(30) not null default '' comment '角色名称'
	)engine=innodb default charset=utf8 comment='角色表';

用户角色关联表
	create table user_role (
		id int auto_increment primary key comment '自增id',
		user_id int not null default 0 comment '用户id',
		role_id int not null default 0 comment '角色id'
	)engine=innodb default charset=utf8 comment '用户角色关联表';

权限表	
	create table permission (
		perm_id int auto_increment primary key comment '权限id',
		perm_type varchar(30) not null default '' comment '权限类型'
	)engine = innodb default charset=utf8 comment '权限表';
	
用户权限关联表	
	create table role_perm (
		id int auto_increment primary key comment '自增id',
		role_id int not null default 0 comment '角色id',
		perm_id int not null default 0 comment '权限id'
	)engine = innodb default charset=utf8 comment '用户权限关联表';
	
	
    