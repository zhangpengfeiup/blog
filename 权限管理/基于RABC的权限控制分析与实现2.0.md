基于角色的权限访问控制 RBAC(Role Based Access Control):

参考:
	https://blog.csdn.net/PainsOnline/article/details/7183613
	https://blog.csdn.net/painsonline/article/details/7183629

自己结合业务的分析如下:
	图片可以查看目录下面的pdf文件:
	https://github.com/zhangpengfeiup/blog/blob/master/%E6%9D%83%E9%99%90%E7%AE%A1%E7%90%86/RBAC%E5%88%86%E6%9E%90.pdf
角色关系:
	一个运营同学可以负责多个代理商或多个广告主，一个代理商可以对应多个广告主，同时也可以有多个二级代理。二级代理商只可以代理广告主，无三级代理商。
	每一个运营同学只能查看自己下面所有广告主信息或者代理商信息。

运营
	代理商
		广告主
		二级代理商
			广告主
	广告主

代理商
	广告主


需求:
	1. 获取该用户组中的所有成员信息
	   查询用户和用户组表获取到用户所在的用户组id，然后查询出所有用户组id为该id的用户。
	
	2. 回去改运营下面所有代理商信息和广告主信息。
	   查询用户和角色关联表获取用户的角色id，判断用户是否为运营。如果为运营获取到对应的组id，
	   然后获取组id为该id或父用户组为该id的用户。（因为有二级代理商所有要获取父用户组id）
