package com.jaovo.msg.dao;

import java.util.List;

import com.jaovo.msg.Util.Pager;
import com.jaovo.msg.model.User;

public interface IUserDao {
	public void add(User user);
	public void delete(int id);
	public void update(User user);
	
	public User load(int id);
//	public User load(String username);
	public User load(String username,String password);
	public List<User> load();
//	public List<User> load(String content);
	
	public Pager<User> load(String content , int pageindex , int pageSize);
	public Pager<User> load(String content);
}
