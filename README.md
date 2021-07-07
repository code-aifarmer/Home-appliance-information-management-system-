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
![屏幕截图(42)](https://user-images.githubusercontent.com/73326606/122860767-e4899b80-d350-11eb-81ad-90a615dcb6d3.png)
![屏幕截图(43)](https://user-images.githubusercontent.com/73326606/122860770-e6ebf580-d350-11eb-9da1-b3b50975f5c6.png)
### 所有的按钮鼠标滑过和点击都有不同的展示效果
### 当你点击选购商品之后：  
![QQ图片20210627101958](https://user-images.githubusercontent.com/73326606/123535680-f22b9080-d757-11eb-9994-aa506549e715.png)
### 由于时间原因就简单糊了一个壳子  
### 点击小风扇那个图标（空调）表示选择空调这个类别，然后可以进入下一个页面进行商品的选择  
![QQ图片20210627102049](https://user-images.githubusercontent.com/73326606/123535715-2c952d80-d758-11eb-85c7-6fd8f221d140.png)
### 点击对应的商品跳转到商品详情页：  
![QQ图片20210627102055](https://user-images.githubusercontent.com/73326606/123535732-433b8480-d758-11eb-8ed0-f8d14335a1ad.png)
### 点击购买即可，这里由于时间原因内容比较少:  
![QQ图片20210627102100](https://user-images.githubusercontent.com/73326606/123535741-58181800-d758-11eb-9474-30d2c0bf3424.png)
### 当你点击申请退货之后:  
![Q$HIEV``1K(MQ9 CQJRCB{Y](https://user-images.githubusercontent.com/73326606/122858836-8f985600-d34d-11eb-81aa-f6191ef3b951.png)  
#### 当你填好对应的信息之后你可以点击提交申请  
![FNF6O4U7OAV9OO )4V155$U](https://user-images.githubusercontent.com/73326606/122858963-cf5f3d80-d34d-11eb-91ca-e167f3f61cf6.png)  
### 当你点击申请维修之后：
![YNI1Q$))RD C4DK} Z0P4@E](https://user-images.githubusercontent.com/73326606/122859055-f3bb1a00-d34d-11eb-835c-a193ab30d320.png)
#### 填好对应的信息，这里的故障类型选择后自动填入维修日期和所需费用并不可更改。  
### 当你点击维修查询之后：  
![FVN%FJNAMT0$}ACZ {S0KW1](https://user-images.githubusercontent.com/73326606/122859221-3bda3c80-d34e-11eb-9ad7-639a385fac9f.png)  
#### 你可以查询到刚才提交的维修申请，并可以跳转到留言板，你可以发表您的高见并查看其他人的评论：  
![Y7M76%UZW `S`JZ)D6K7~_Q](https://user-images.githubusercontent.com/73326606/122859422-95426b80-d34e-11eb-866c-8e2bb10caf10.png)
![85 T__C7_0KW~6_W486MVIF](https://user-images.githubusercontent.com/73326606/122859431-9b384c80-d34e-11eb-9994-be57587acd30.png)  
![_}K8ZZC%P VR$CU_ISA(9{D](https://user-images.githubusercontent.com/73326606/122859558-c884fa80-d34e-11eb-86c6-9fd0f14d4303.png)
### 当你点击联系客服（人工智障）之后：  
![QQ图片20210623125050](https://user-images.githubusercontent.com/73326606/123037797-deafbb00-d421-11eb-9b79-5b80f7c452b0.png)
#### 这里是接入了青云客的一个图灵机器人的一个接口，白嫖了人家的机器人也不好多说什么:eyes::eyes:  
#### 语音输入是接入了百度ai的语音识别
![QQ图片20210623125127](https://user-images.githubusercontent.com/73326606/123037881-0868e200-d422-11eb-8a1e-d0652e61c5db.png)
### 顾客的大概就这些，下面介绍经理的通道：  
### 当你以经理的身份登录（经理的账号只有一个且不能注册）:  
![4YS `E@Q`}W`JL_ }FV}O_W](https://user-images.githubusercontent.com/73326606/122859886-51039b00-d34f-11eb-9e51-efed738afd26.png)  
### 登陆之后就可以看到经理通道，这个页面下可以看到所有已经注册的用户的信息。  
![{20QWNDCP{R2SH@AT5WRR1Q](https://user-images.githubusercontent.com/73326606/122859958-72fd1d80-d34f-11eb-96f2-ab217e206225.png)  
#### 选中一个用户之后点击按钮“选中后点击查看”进入到下一个页面  
![O @78%1QO@RT 8FOIXCLFXR](https://user-images.githubusercontent.com/73326606/122860175-db4bff00-d34f-11eb-91bf-9f505e137160.png)
### 这个页面可以看到对应用户的退货信息和维修信息，经理可以在对应的页面里选中对应的申请点击拒绝或者批准进行处理。  
![O7%@{_Q58J9S NV}{%5M{V6](https://user-images.githubusercontent.com/73326606/122860261-ff0f4500-d34f-11eb-9088-e570538bf80e.png)
#### 例如拒绝这个维修申请。










