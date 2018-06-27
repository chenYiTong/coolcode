<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib uri="http://jsptags.com/tags/navigation/pager" prefix="pg"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
	<head>
		<title>分页测试</title>
	</head>
	<body>
	<!-- 
		数据总条数 ; 每页显示的最大条数 ; 显示的页码数
		将遍历的pageNumber赋值给当前的页码数
	 -->
	<pg:pager items="1000" maxPageItems="15" maxIndexPages="10" export="curpage = pageNumber">
		<pg:first>
			<a href="<%=pageUrl %>">首页</a>
		</pg:first>
		<pg:prev>
			<a href="<%=pageUrl %>">上一页</a>
		</pg:prev>
		
		<pg:pages>
			<%
				if(curpage == pageNumber){
			%>
			[<%=pageNumber %>]
			<%
				}else{
			%>
			<a href="<%=pageUrl %>"><%=pageNumber %></a>
			<%
				}
			%>
		</pg:pages>
		
		<pg:next>
			<a href="<%=pageUrl %>">下一页</a>
		</pg:next>
		<pg:last>
			<a href="<%=pageUrl %>">尾页</a>
		</pg:last>
		
	</pg:pager>
	
	</body>
</html>
