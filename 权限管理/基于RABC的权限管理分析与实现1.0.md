RABCȨ�޹���:
	https://blog.csdn.net/painsonline/article/details/7183613/

����:
    v1.0: 
	�����û��Ľ�ɫ��Ϣȥ�ж��û��Ƿ��н����ҳ���Ȩ�ޡ�һ���û������ж����ɫ���û���Ȩ�������н�ɫ��Ȩ��֮�͡�
	��ɫ��Ϣ��ÿһ����ɫ�в�ͬ��Ȩ����Ϣ��
	Ȩ����Ϣ: ϵͳ�У�Ȩ�ޱ��ֵ���ʽ��ʲô���Թ��ܵĲ��������ϴ��ļ����޸ģ��˵��ķ��ʣ�ҳ���ϵ�Ԫ�ص���ʾ��ͼƬ����ʾ��
����Ȩ�޵ķ�Χ��

�û���:
create table user(
user_id int primary key auto_increment  comment '�û�id',
user_name varchar(50) not null default '' comment '�û���',
user_passwd varchar(50) not null default '' comment '�û�����',
)engine=innodb default charset=utf8 comment '�û���';

��ɫ��	
	create table role (
		role_id int auto_increment primary key comment '��ɫid',
		role_name varchar(30) not null default '' comment '��ɫ����'
	)engine=innodb default charset=utf8 comment='��ɫ��';

�û���ɫ������
	create table user_role (
		id int auto_increment primary key comment '����id',
		user_id int not null default 0 comment '�û�id',
		role_id int not null default 0 comment '��ɫid'
	)engine=innodb default charset=utf8 comment '�û���ɫ������';

Ȩ�ޱ�	
	create table permission (
		perm_id int auto_increment primary key comment 'Ȩ��id',
		perm_type varchar(30) not null default '' comment 'Ȩ������'
	)engine = innodb default charset=utf8 comment 'Ȩ�ޱ�';
	
�û�Ȩ�޹�����	
	create table role_perm (
		id int auto_increment primary key comment '����id',
		role_id int not null default 0 comment '��ɫid',
		perm_id int not null default 0 comment 'Ȩ��id'
	)engine = innodb default charset=utf8 comment '�û�Ȩ�޹�����';
	
	
    