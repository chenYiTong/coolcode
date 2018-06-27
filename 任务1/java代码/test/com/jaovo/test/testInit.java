package com.jaovo.test;

import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Random;

/*
 * 	
 *  insert into t_user (username , password , nickname , type,status) value(?,?,?,?,?)
 *  
 *  random
 *  
 */
public class testInit {
	public static void main(String[] args) {
		generate();
	}
	public static void generate() {
		PrintWriter out = null;
		String sql = null;
		
		try {
			out = new PrintWriter("F:\\JavaTools\\DBTools\\SQLTools\\insert.sql");
			for(int i = 0 ; i < 300 ;i++) {
				sql = "insert into t_user value (\"" + ranName() +" \" "+ ranSex() +"\" " + ranBron()+" \")" ; 
				out.println(sql);
				out.flush();
			}
			out.flush();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		
	}
	//创建一个随机数生成器
	static Random random = new Random();
	//生成出生日期的方法
	static String begin = "1970-01-01";
	static String end = "2008-08-08";
	
	static SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy-mm-dd");
	private static String ranBron() {
		String stringDate = null;
		try {
			Date startDate =  simpleDateFormat.parse(begin);
			Date endDate =  simpleDateFormat.parse(end);
			
			long time = randomRange(startDate.getTime(),endDate.getTime());
			
			Date date = new Date(time);
			
			stringDate = simpleDateFormat.format(date);
		} catch (ParseException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return stringDate;
	}
	private static long randomRange(long start, long end) {
		return (long)(Math.random()*(end-start) + start);
	}
	private static String ranSex() {
		if (random.nextInt(2) == 0) {
			return "男";
		}
		return "女";
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
