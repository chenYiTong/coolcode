package com.jaovo.test;

import java.util.Random;

import com.jaovo.msg.Util.DaoFactory;
import com.jaovo.msg.dao.IUserDao;
import com.jaovo.msg.model.User;

public class initsql {
	public static void main(String[] args) {
		IUserDao userDao = DaoFactory.getDaoImpl();
		
		for(int i = 0 ; i < 300 ; i++) {
			User user  = new User();
			user.setUsername("user" + i);
			user.setPassword("root");
			user.setNickname(ranName());
			user.setType(0);
			user.setStatus(0);
			userDao.add(user);
		}
		System.out.println("------------------");
	}
	static String[] firstName = new String[]{
			"赵","钱","孙","李","张","庞","陈","杨","王","刘","牛","爱新觉罗","西门","上官","闻人","万俟","诸葛","司马","公羊"
		};
		static String[] middleName = new String[]{
			"建","爱","小","大","少","晓","美","伟","婷"
		};
		static String[] lastName = new String[]{
			"琪","国","民","丹","宇","超","磊","静","婷","强","军","亮"
		};
		
		static Random random = new Random();
		
		private static String ranName() {
			int num = random.nextInt(4);
			if (num <=1 ) {
				return firstName[random.nextInt(firstName.length)]
						+ middleName[random.nextInt(middleName.length)]
						+ lastName[random.nextInt(lastName.length)];
				
			}else {
				return firstName[random.nextInt(firstName.length)]
						+ lastName[random.nextInt(lastName.length)];
			}
			
		}
}
