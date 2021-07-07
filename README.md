# 狗屎代码（
## 首先自我批评，文件命名当时不知道怎么想的，给自己挖了一个大坑，中途想改过来也无力回天。:sob::sob::sob:
### 软件工程基础的一个作业，糊了一个家电信息管理系统
![65UPPJYPUFL@~)7FFYWP4M5](https://user-images.githubusercontent.com/73326606/124718590-d20a8700-df38-11eb-8c28-61c6b962fd2c.png)
### 正脸就长这样:joy::joy:
#### 我承认我审美能力为负，最开始的时候比这个还要阴间，就是一个地府管理系统，就不拿出来了，多亏了BladeHiker的审美能力一直在线。
### 下面我就简单介绍一下吧
#### 主要的功能如下：  
#### 用户的登录，注册，用户申请维修，申请退货，维修结果查询，对维修的结果进行评论以及查看其他人的评论，联系客服。  
#### 经理的登录，经理查看所有已经注册的用户，经理对任何用户的维修申请和退货申请进行拒绝或者批准。
### 注册页面如下：   
![_7$E6T9JRSZ3F~C4Z@8WKJ3](https://user-images.githubusercontent.com/73326606/124718704-f4040980-df38-11eb-9910-41be4a556288.png)
#### 按照相关提示填入对应的信息即可完成注册，当然，填入不对应的信息你也可以完成注册:fu:  
### 注册好之后你就可以选中"我是顾客"那个按钮，然后填入刚刚注册好的账号密码并点击登录即可进入顾客通道。  
![G5VG8PMS1LSW4X71Q1QU$WW](https://user-images.githubusercontent.com/73326606/124718826-14cc5f00-df39-11eb-8d5f-e1aa941e1fd9.png)
### 这里是找回密码功能。通过SMTP实现:    
![E_K(4_N{7EBE53{8@NQ15L7](https://user-images.githubusercontent.com/73326606/124719020-4a714800-df39-11eb-9411-f207d4d519fb.png)
![2QC}BD6CENPD0U M_TB N)N](https://user-images.githubusercontent.com/73326606/124719549-d97e6000-df39-11eb-87cc-d75e816b7454.png)
### 通过向qq邮箱发送一个由数字和大小写字母组成的验证码进行验证，并修改密码，如果两次输入的密码不一致或者验证码不正确会进行提示  
![$1D`{U() 8) @BI1K0L5GRK](https://user-images.githubusercontent.com/73326606/124719705-02065a00-df3a-11eb-81c1-c03684e5897f.png)
![VG%VG47H}2LD$2~78KXPRN1](https://user-images.githubusercontent.com/73326606/124719847-27936380-df3a-11eb-990e-f6bdec37e8de.png)
![S 1H02_Q$_W36U6WF@6_CL](https://user-images.githubusercontent.com/73326606/124720094-5ad5f280-df3a-11eb-8e9e-6f08e586cae6.png)
### 顾客通道这个页面主要分为六个模块，分别是选购商品，申请退货，维修查询，申请维修，联系客服和退出  
![G5VG8PMS1LSW4X71Q1QU$WW](https://user-images.githubusercontent.com/73326606/124720273-8f49ae80-df3a-11eb-8edd-f11dcec69155.png)
![屏幕截图(47)](https://user-images.githubusercontent.com/73326606/124720620-e9e30a80-df3a-11eb-8d36-a24e3655efdd.png)
![屏幕截图(48)](https://user-images.githubusercontent.com/73326606/124720634-ecddfb00-df3a-11eb-80a8-76e5d1092f7e.png)
### 所有的按钮鼠标滑过和点击都有不同的展示效果
### 当你点击选购商品之后：  
![VA1F_ZSEZW7RDL6F)F0W503](https://user-images.githubusercontent.com/73326606/124720789-172fb880-df3b-11eb-94de-57fd6e6fd334.png)
### 由于时间原因就简单糊了两个类别    
### 点击小风扇那个图标（空调）表示选择空调这个类别，然后可以进入下一个页面进行商品的选择  
![(3IK7ID O55FKUVT7M1U4DO](https://user-images.githubusercontent.com/73326606/124720913-34648700-df3b-11eb-8a7d-02b2b0a30d0d.png)
### 点击对应的商品跳转到商品详情页：  
![8{CX$ RGAWFNN(CG~G~PQ5](https://user-images.githubusercontent.com/73326606/124721069-5e1dae00-df3b-11eb-839a-21def2e4241c.png)
### 点击购买即可，相应的库存也会随之变化:  
![VNQ9X4EE}`BDOAMJ5Y6ZS6Y](https://user-images.githubusercontent.com/73326606/124721404-accb4800-df3b-11eb-83a0-baad02d165e8.png)
![52RKB 3`WL3~BRP0EPG}7WP](https://user-images.githubusercontent.com/73326606/124721280-8e654c80-df3b-11eb-9f7f-790d70889b6e.png)
### 当你点击申请退货之后:  
![LK%NK7 }2@~(TD(C3AU~@C8](https://user-images.githubusercontent.com/73326606/124721666-e3a15e00-df3b-11eb-929d-f6f18ae61b4a.png)
#### 当你填好对应的信息之后你可以点击提交申请  
![NT_}YHW`MNYL4PI}}I@_8IA](https://user-images.githubusercontent.com/73326606/124721860-0fbcdf00-df3c-11eb-80cb-4994e9862589.png)
### 当你点击申请维修之后：
![PN@5QM6O V43O71GHALM%LC](https://user-images.githubusercontent.com/73326606/124722060-4266d780-df3c-11eb-96df-6dee9c1b29e9.png)
#### 填好对应的信息，这里的故障类型选择后自动填入维修日期和所需费用，并且不可更改。  

### 当你点击维修查询之后：  
![}J){73PFVA HUXN{FN)PJBW](https://user-images.githubusercontent.com/73326606/124722645-d33db300-df3c-11eb-9d70-1a7e64eb8d20.png)
### 点击维修查询之后，如果你有维修申请的话，那么除了会弹出提示框以外还会跳转到维修结果查询页面。  
![BN CJ~U$F8PNQS736(05ZWV](https://user-images.githubusercontent.com/73326606/124722903-1435c780-df3d-11eb-92ec-7b56cc2c6bfc.png)
#### 你可以查询到刚才提交的维修申请，并可以通过点击“去评价”跳转到留言板，你可以发表您的高见并查看其他人的评论：  
![% 4P2TP`97JKSH)BBJW%9GA](https://user-images.githubusercontent.com/73326606/124723293-7abae580-df3d-11eb-9e20-08e1e038e2db.png)
![CMYO7ZYBN5$%2%CAB{9Y5AF](https://user-images.githubusercontent.com/73326606/124723404-9c1bd180-df3d-11eb-852f-29bfacc0fe4c.png)
![7`IZ9POHLER@`CY{G81S6`R](https://user-images.githubusercontent.com/73326606/124723879-0e8cb180-df3e-11eb-9802-2733821f5ec0.png)


### 当你点击联系客服（人工智障）之后：  
![R~P3RY6NTUAFE$Z`H@H84LP](https://user-images.githubusercontent.com/73326606/124724300-793ded00-df3e-11eb-827d-ba93dd6486f4.png)
#### 这里是接入了青云客的一个图灵机器人的一个接口，白嫖了人家的机器人也不好多说什么:eyes::eyes:  
#### 语音输入是接入了百度ai的语音识别,效果很nice
![_J{N 7ZM` W8_JY6(AMWG`A](https://user-images.githubusercontent.com/73326606/124724427-92469e00-df3e-11eb-82bb-707de885f339.png)
### 顾客的大概就这些，下面介绍经理的通道：  
### 当你以经理的身份登录（经理的账号只有一个且不能注册）:  
![0RRY0K71@8{~FOY1IGZPB)F](https://user-images.githubusercontent.com/73326606/124724681-c9b54a80-df3e-11eb-8e10-c40a689cdcca.png)
### 登陆之后就可以看到经理通道，这个页面下可以看到用户管理和库存管理两个模块。  
![{20QWNDCP{R2SH@AT5WRR1Q](https://user-images.githubusercontent.com/73326606/122859958-72fd1d80-d34f-11eb-96f2-ab217e206225.png)  
#### 选中一个用户之后点击按钮“选中后点击查看”进入到下一个页面  
![O @78%1QO@RT 8FOIXCLFXR](https://user-images.githubusercontent.com/73326606/122860175-db4bff00-d34f-11eb-91bf-9f505e137160.png)
### 这个页面可以看到对应用户的退货信息和维修信息，经理可以在对应的页面里选中对应的申请点击拒绝或者批准进行处理。  
![O7%@{_Q58J9S NV}{%5M{V6](https://user-images.githubusercontent.com/73326606/122860261-ff0f4500-d34f-11eb-9088-e570538bf80e.png)
#### 例如拒绝这个维修申请。










