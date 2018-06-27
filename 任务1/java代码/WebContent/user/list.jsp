<%@page import="com.jaovo.msg.Util.Pager"%>
<%@page import="com.jaovo.msg.model.User"%>
<%@page import="java.util.List"%>
<%@page import="com.jaovo.msg.dao.UserDaoImpl"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>用户展示界面</title>
<style type="text/css">
	a:link{
		color:#0cc;
		text-decoration: none;
	}
	a:visited{
		color:#0cc;
		text-decoration: underline;
	}
	a:hover{
		color:#c00;
		text-decoration: none;
		position: relative;
		top:1px;
		left:1px;
	}
	a:active{
		color:#00f;
		text-decoration: none;
	}
</style>
</head>
<%
	//筛选
	String content = request.getParameter("content");
	if(content == null || "".equals(content)){
		content = "";
	}
	UserDaoImpl userDao = new UserDaoImpl();
// 	List<User> users = userDao.load(content);
	Pager pager = userDao.load(content);
	//获得pager中保存的list集合
	List<User> users = pager.getDatas();
	//获取登录用户
	User loginuser = (User)session.getAttribute("loginUser");
%>
<body>
	<jsp:include page="inc.jsp" >
		<jsp:param name="op" value="展示" />
	</jsp:include>
	<table align="center" border="1" width="700">
		<tr>
			<form action="list.jsp" method="post">
				<td colspan="8">
					请输入用户名或昵称 : &nbsp;
					<input type="text" name="content" size="70" /> &nbsp; 
					<input type="submit" value="搜索" />
				</td>
			</form>
		</tr>
<!-- 		<tr> -->
<!-- 			<td colspan="8"> -->
<%-- 				一共有<%=pager.getTotalRecord() %>条数据 , 每页显示<%=pager.getPageSize() %>条数据 --%>
<%-- 				页码 : <%=pager.getPageIndex() %> / <%=pager.getTotalPage() %> --%>
<!-- 			</td> -->
<!-- 		</tr> -->
		<tr>
			<td>用户编号</td>
			<td>用户名称</td>
			<td>用户密码</td>
			<td>用户昵称</td>
			<td>用户类型</td>
			<td>用户状态</td>
			<td colspan="2">用户操作</td>
		</tr>
		<%
			for( User user : users ){
		%>
		<tr>
			<td> <%=user.getId() %></td>
			<td> <%=user.getUsername() %></td>
			<td> <%=user.getPassword() %></td>
			<td> <%=user.getNickname() %></td>
			<td>
				<%
					if(user.getType() == 0){
				%>
					<span style="color:#000000;font-family: 楷体">普通用户</span>
					<%
						if(loginuser.getType() == 1){
					%>
						<a href="setType.jsp?id=<%=user.getId() %>">设置为管理员</a>
					<%
						}
					%>
				<%
					}else{
				%>	
					<span style="color:#ffff00;font-family: 楷体">管理员</span>
					<%
						if(loginuser.getType() == 1){
					%>
						<a href="setType.jsp?id=<%=user.getId() %>">取消管理员</a>
					<%
						}
					%>
				<%
					}
				%>
			</td>
			
			
			<td>
				<%
					if(user.getStatus() == 0){
				%>
					启用
					<%
						if(loginuser.getType() == 1){
					%>
						<a href="setStatus.jsp?id=<%=user.getId() %>">禁用</a>
					<%
						}
					%>
				<%
					}else{
				%>	
					<font color="red">禁用</font>
					<%
						if(loginuser.getType() == 1){
					%>
						<a href="setStatus.jsp?id=<%=user.getId() %>">启用</a>
					<%
						}
					%>
				<%	
					}
				%>
			</td>
			
			
			
			<td> <a href="delete.jsp?id=<%=user.getId() %>" >删除</a></td>
			<td> <a href="updateInput.jsp?id=<%=user.getId() %>" >更新</a></td>
			
		</tr>
		<%
			}
		%>
		
		<tr>
			<td colspan="8" align="center">
				<jsp:include page="../inc/pager.jsp">
					<jsp:param name="items" value="<%=pager.getTotalRecord() %>" />
				</jsp:include>
			</td>
		</tr>
		
	</table>
</body>
</html>