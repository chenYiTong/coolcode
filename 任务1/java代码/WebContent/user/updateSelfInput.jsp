<%@page import="com.jaovo.msg.Util.ValidateUtil"%>
<%@page import="com.jaovo.msg.Util.DaoFactory"%>
<%@page import="com.jaovo.msg.dao.IUserDao"%>
<%@page import="com.jaovo.msg.model.User"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>更新个人信息</title>
<!-- 更改个人信息,更改的是登录的这个用户 -->
</head>
<%
	User user = (User)session.getAttribute("loginUser");
%>
<body>
	<jsp:include page="inc.jsp" >
		<jsp:param name="op" value="更新" />
	</jsp:include>
	
	<form action="updateSelf.jsp" method="get">
		<table align="center" border="1" width="500">
		<!-- 这个id 不需要再页面上显示 , 就作为一个隐藏域传到服务器 -->
			<input type="hidden" name="id" value="<%=user.getId() %>" />
			<tr>
				<td>用户名称 : </td>
				<td>
					<input type="text" name="username" value="<%=user.getUsername() %>" />
					<%=ValidateUtil.showError(request, "username") %>
				</td>
			</tr>
				<tr>
    			<td>用户密码:</td>
    			<td>
    				<input type="password" name="password" />
    				<%=ValidateUtil.showError(request, "password") %>
    			</td>
    		</tr>
    		<tr>
    			<td>用户昵称:</td>
    			<td>
    				<input type="text" name="nickname" value="<%=user.getNickname() %>" />
    				<%=ValidateUtil.showError(request, "nickname") %>
    			</td>
    		</tr>
    		<tr align="center">
    			<td colspan="2">
    				<input type="submit" value="提交" />
    				<input type="reset" value="重置" />
    			</td>
    		</tr>
		</table>
	</form>
</body>
</html>