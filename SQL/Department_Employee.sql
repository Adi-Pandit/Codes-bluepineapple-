use bluepineapple;

drop table if exists employee;
drop table if exists department;

CREATE TABLE department (
    dept_no INT PRIMARY KEY,
    dname VARCHAR(30)
);
CREATE TABLE employee (
    emp_no INT PRIMARY KEY,
    ename VARCHAR(30),
    salary INT,
    designation VARCHAR(30),
    doj DATE,
    dept_no INT,
    FOREIGN KEY (dept_no)
        REFERENCES department (dept_no)
);

desc department;
desc employee;

insert into department(dept_no,dname) values(1,'Testing');
insert into department(dept_no,dname) values(2,'IT');
insert into department(dept_no,dname) values(3,'Support');
insert into department(dept_no,dname) values(4,'BPO');
insert into department(dept_no,dname) values(5,'Security');
insert into department(dept_no,dname) values(6,'RND');

insert into employee(emp_no, ename, salary, designation, doj, dept_no) values(1001,'Aditya',200000,'Manager','2020/12/23',1);
insert into employee(emp_no, ename, salary, designation, doj, dept_no) values(7056,'Aadesh',20000,'Developer','2020/12/23',2);
insert into employee(emp_no, ename, salary, designation, doj, dept_no) values(1095,'Abhinav',35000,'HR','2018/12/12',1);
insert into employee(emp_no, ename, salary, designation, doj, dept_no) values(2015,'Piyush',20000,'Accountant','2017/12/23',3);
insert into employee(emp_no, ename, salary, designation, doj, dept_no) values(7369,'Pranav',200000,'Manager','2015/12/23',4);
insert into employee(emp_no, ename, salary, designation, doj, dept_no) values(7895,'Atharav',20000,'Testing','2020/12/23',5);
insert into employee(emp_no, ename, salary, designation, doj, dept_no) values(7900,'Niranjan',15000,'Security','2021/12/23',5);

SELECT 
    *
FROM
    department;
    
SELECT 
    *
FROM
    employee;

/* INNER JOIN */
SELECT 
    department.dept_no,
    employee.emp_no,
    employee.ename,
    employee.designation,
    employee.doj
FROM
    department
        INNER JOIN
    employee ON department.dept_no = employee.dept_no;
 
/* LEFT JOIN */
SELECT 
    department.dept_no,
    employee.emp_no,
    employee.ename,
    employee.designation,
    employee.doj
FROM
    department
        LEFT JOIN
    employee ON department.dept_no = employee.dept_no;
 
/* RIGHT JOIN */
SELECT 
    department.dept_no,
    employee.emp_no,
    employee.ename,
    employee.designation,
    employee.doj
FROM
    department
        RIGHT JOIN
    employee ON department.dept_no = employee.dept_no;

/* FULL OUTER JOIN */    
SELECT 
    department.*,
    employee.*
FROM
    department
        LEFT JOIN
    employee ON department.dept_no = employee.dept_no 
UNION SELECT 
    department.*,
    employee.*
FROM
    department
        RIGHT JOIN
    employee ON department.dept_no = employee.dept_no;

/* GROUP BY */
SELECT emp_no, ename, salary, designation, doj from employee group by emp_no, ename having salary>20000;