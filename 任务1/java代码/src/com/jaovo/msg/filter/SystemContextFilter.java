package com.jaovo.msg.filter;

import java.io.IOException;

import javax.servlet.Filter;
import javax.servlet.FilterChain;
import javax.servlet.FilterConfig;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;

import com.jaovo.msg.Util.systemContext;

public class SystemContextFilter implements Filter {
	private int  pageSize;
	
	public SystemContextFilter() {
	}

	@Override
	public void init(FilterConfig filterConfig) throws ServletException {
		try {
			pageSize = Integer.parseInt(filterConfig.getInitParameter("pagesize"));
		}catch (Exception e) {
			pageSize = 15;
		}
		
	}

	@Override
	public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain)
			throws IOException, ServletException {
//		int pageIndex = 1;
//		int pageSize = 20;
		int pageOffset = 0;
		try {
			try {
//				pageIndex = Integer.parseInt(request.getParameter("pageIndex"));
				pageOffset = Integer.parseInt(request.getParameter("pager.offset"));
			}catch(Exception e) {
			}
			systemContext.setPageSize(pageSize);
			systemContext.setPageOffset(pageOffset);
			
			chain.doFilter(request, response);
		}finally {
			//filter过滤的是一次完整的请求 , 在请求完成之后 , 就把设置的值删除
//			systemContext.removePageIndex();
			systemContext.removePageSize();
			systemContext.removePageOffset();
		}
	}

	@Override
	public void destroy() {

	}
}
