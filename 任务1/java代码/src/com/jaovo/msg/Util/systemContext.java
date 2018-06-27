package com.jaovo.msg.Util;

public class systemContext {
	//声明两个线程局部变量
	private static ThreadLocal<Integer> pageSize = new ThreadLocal<Integer>();
	private static ThreadLocal<Integer> pageIndex = new ThreadLocal<Integer>();
	
	//set.get.remove 分贝对线程局部变量进行设置,获取和删除的操作
	
	public static int getPageSize() {
		return pageSize.get();
	}
	public static void setPageSize(int pageSize) {
		systemContext.pageSize.set(pageSize);
	}
	public static void removePageSize() {
		systemContext.pageSize.remove();
	}
	
	public static int getPageIndex() {
		return pageIndex.get();
	}
	public static void setPageIndex(int pageIndex) {
		systemContext.pageIndex.set(pageIndex);
	}
	public static void removePageIndex() {
		systemContext.pageIndex.remove();
	}
	//使用框架分页的话,在客户端传递过来的参数不再是pageIndex , page.Offset
	private static ThreadLocal<Integer> pageOffset = new ThreadLocal<Integer>();
	
	public static int getpageOffset() {
		return pageOffset.get();
	}
	public static void setPageOffset(int pageOffset) {
		systemContext.pageOffset.set(pageOffset);
	}
	public static void removePageOffset() {
		systemContext.pageOffset.remove();
	}
}
