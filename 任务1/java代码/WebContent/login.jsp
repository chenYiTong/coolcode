<%@page import="com.jaovo.msg.Util.UserException"%>
<%@page import="com.jaovo.msg.model.User"%>
<%@page import="com.jaovo.msg.Util.DaoFactory"%>
<%@page import="com.jaovo.msg.dao.IUserDao"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<%
	//获取客户端传递过来的参数
	String username = request.getParameter("username");
	String password = request.getParameter("password");
	try{
	IUserDao userDao = DaoFactory.getDaoImpl();
	User user = userDao.load(username,password);
	
	session.setAttribute("loginUser", user);
// 	response.sendRedirect("user/list.jsp");
	response.sendRedirect(request.getContextPath() +"/user/list.jsp");
	}catch(UserException e){
		//验证出错
		request.setAttribute("loginError", e.getMessage());
%>
	<<jsp:forward page="LoginInput.jsp"></jsp:forward>
<%
	}
%>