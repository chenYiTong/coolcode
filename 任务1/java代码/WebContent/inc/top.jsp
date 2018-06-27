<%@page import="com.jaovo.msg.model.User"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<%
	//获取session中保存的用户
	User user = (User)session.getAttribute("loginUser") ;
%>
<div style="color:red ; text-align: right ;border-bottom: 1px solid #000;">
	欢迎[<%=user.getNickname() %>]使用该系统&nbsp;
	<a href="<%=request.getContextPath()%>/Logout.jsp">退出系统</a>&nbsp;
	<a href="<%=request.getContextPath()%>/user/updateSelfInput.jsp">更改个人信息</a>
</div>