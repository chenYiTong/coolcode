﻿<%@page import="com.jaovo.msg.Util.ValidateUtil"%>
<%@page import="com.jaovo.msg.Util.UserException"%>
<%@page import="com.jaovo.msg.dao.UserDaoImpl"%>
<%@page import="com.jaovo.msg.model.User"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<%
	//接收客户端传递过来的参数
	String username = request.getParameter("username");
	String password = request.getParameter("password");
	String nickname = request.getParameter("nickname");
	boolean validate = ValidateUtil.validateNull(request, new String[]{"username","password","nickname"});
	if(!validate){
%>
	<jsp:forward page="addInput.jsp"></jsp:forward>
<%
	}
	User user = new User();
	user.setUsername(username);
	user.setPassword(password);
	user.setNickname(nickname);
	UserDaoImpl userDao = new UserDaoImpl();
	try{
		
	userDao.add(user);
	//重定向
	response.sendRedirect("list.jsp");
%>

<%
	}catch(UserException e){
%>
	<h2 style="color:red ; font-size:50px">发生错误 : <%=e.getMessage() %></h2>
	<%
	}
	%>
</html>