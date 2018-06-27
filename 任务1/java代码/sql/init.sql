-- mysal -u root -p root;
-- show databases;
-- drop database jaovo_shop;

create database jaovo_msg;
use jaovo_msg;
GRANT ALL ON jaovo_msg.* to "jaovo"@"localhost" IDENTIFIED BY "root";
create table t_user(
 	id int(10) primary key auto_increment,
 	username varchar(255),
 	password varchar(255),
 	nickname varchar(255),
 	type int(2),
 	status int(2)
);

create table t_message(
   id  		int(10) primary key auto_increment,            	
   title                varchar(254),
   content              text,
   post_date             datetime,
   user_id               int(10),
   CONSTRAINT FOREIGN KEY(user_id) REFERENCES t_user(id)
);

create table t_comment(
   id  	  int(10) primary key auto_increment,  
   content       text,
   post_date     datetime,
   user_id       int(10),
   msg_id        int(10),
   CONSTRAINT FOREIGN KEY(user_id) REFERENCES t_user(id),
   CONSTRAINT FOREIGN KEY(msg_id) REFERENCES t_message(id)
);

分页语句 : select  * from t_user where name = ? limit ?,?

分页条件 : 
     页码数 : pageIndex
     数据总条数 : totalRecord
     每一页显示的条数 pageSize
     页数 : totalPage = totalRecord%pageSize == 0 ? totalRecord/pageSize : totalRecord/pageSize + 1
     
     每一页显示的数据的起始下标 pageOffset = pageSize*(pageIndex - 1) + 1
     每一页显示的数据的结束下标 pageOffset2 = pageSize*pageIndex
     
     
     
     
     
     
     
     
     
     
     
     
     
     
