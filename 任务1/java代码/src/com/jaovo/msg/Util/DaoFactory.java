package com.jaovo.msg.Util;

import com.jaovo.msg.dao.UserDaoImpl;

public class DaoFactory {
	public static UserDaoImpl getDaoImpl() {
		return new UserDaoImpl();
	}
}
