#include "gtk/gtk.h"
 

void Poker_show()
{
    GtkWidget *window;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

}


/*改进的回调函数，传递到该函数的数据将会被打印到标准输出*/
void callback(GtkWidget *widget,gpointer data)
{
    g_print(" %s \n",(gchar*) data);
}
 
/*关闭窗口的函数*/
void destroy(GtkWidget *widget,gpointer data)
{
    g_print("退出游戏!\n");
    gtk_main_quit();
}
 
int main(int argc,char *argv[])
{
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *box1; 
    GtkWidget *ImageBox;
    /* 函数gtk_init()会在每个GTK的应用程序中调用。
     * 该函数设定默认的视频和颜色默认参数，接下来会调用函数
     * gdk_init()该函数初始化要使用的库，设定默认的信号处理
     * 检查传递到程序的命令行参数
     * */
    gtk_init(&argc,&argv);
    
    //下面两行创建并显示窗口。创建一个400*400的窗口。
    
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    //弹窗模式 窗口没有边框 （不会出现关闭最小化的点击标识）
    //window = gtk_window_new(GTK_WINDOW_POPUP);
	 
    /*设置窗口标题*/
    gtk_window_set_title(GTK_WINDOW(window),"Welcome to play This game");
 
    g_signal_connect(G_OBJECT(window),"delete_event",G_CALLBACK(destroy),NULL);
    
    //设置窗口在屏幕中间显示
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    //设置窗口最小大小 400 * 300
    gtk_widget_set_size_request(window, 200,150);
    
    //固定窗口大小
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

    /*设置窗口边框的宽度*/
    gtk_container_set_border_width(GTK_CONTAINER(window),400);
 
    /*
     *创建一个组装盒
     *我们看不见它，用来放置按钮
     */
    box1 = gtk_hbox_new(FALSE, 0);
 
    /*把组装盒box1放到主窗口中*/
    gtk_container_add(GTK_CONTAINER(window), box1);


    /*
     *创建一个组装盒
     *我们看不见它，用来放置图片
     */
    ImageBox = gtk_hbox_new(TRUE, 10);
 
    /*把组装盒box1放到主窗口中*/
    gtk_container_add(GTK_CONTAINER(window), ImageBox);
 
    //创建一个图片控件
    GtkWidget *image_one = gtk_image_new_from_file("/home/liuchengchen/workspace/zjh/PokerImage/21.jpg");
    //将image_one添加到hbox
    gtk_container_add(GTK_CONTAINER(box1), image_one);

 
    //创建一个图片控件
    GtkWidget *image_two = gtk_image_new_from_file("/home/liuchengchen/workspace/zjh/PokerImage/22.jpg");
    //将image_one添加到hbox
    gtk_container_add(GTK_CONTAINER(box1), image_two);
    
    //创建一个图片控件
    GtkWidget *image_three = gtk_image_new_from_file("/home/liuchengchen/workspace/zjh/PokerImage/23.jpg");
    //将image_one添加到hbox
    gtk_container_add(GTK_CONTAINER(box1), image_three);

/*
    //5.通过GdkPixbuf来写该图片大小
    //5.1创建pixbuf，需要占用资源，使用完需要释放
    GdkPixbuf *src = gdk_pixbuf_new_from_file("/home/liuchengchen/workspace/zjh/PokerImage/23.jpg", NULL);
    //5.2修改图片大小
    GdkPixbuf *dst = gdk_pixbuf_scale_simple(src, 100, 150, GDK_INTERP_BILINEAR);
    GtkWidget *image_two = gtk_image_new_from_pixbuf(dst);
    //5.3pixbuf使用完需要释放其中资源
    g_object_unref(src);
    g_object_unref(dst);
    //5.4将image_two添加到box1中
    gtk_container_add(GTK_CONTAINER(box1), image_two);


    //6.获取图片控件里的pixbuf,并以这个pixbuf又重新创建一个控件
    GdkPixbuf *tmp = gtk_image_get_pixbuf(GTK_IMAGE(image_two));
    GtkWidget *image_three = gtk_image_new_from_pixbuf(tmp);
    gtk_container_add(GTK_CONTAINER(box1), image_three);

*/

    /*创建一个标签为“欢迎”的按钮*/
    button = gtk_button_new_with_label("看上");
 
    /*当按下欢迎按钮时，我们调用 callback函数，会打印出我们传递的参数*/
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(callback), "准备");
 
    /*我们将button 按钮放入组装盒中*/
    gtk_box_pack_start(GTK_BOX(box1), button, TRUE, TRUE, 0);
 
    /*欢迎按钮设置成功，别忘了写下个函数来显示它*/
    gtk_widget_show(button);
 
    /*创建第二个按钮*/
    button = gtk_button_new_with_label("看牌");
 
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(callback), "游戏开始！");
 
    gtk_box_pack_start(GTK_BOX(box1), button, TRUE, TRUE, 0);
 
    gtk_widget_show(button);
 
    /*创建一个退出按钮*/
    button = gtk_button_new_with_label("闷");
 
    /*当点击退出按钮时，会触发gtk_widet_destroy来关闭窗口，destroy信号从这里发出
     * 会触发destroy函数。*/
    g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(destroy),NULL);
    
    g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(gtk_widget_destroy),window);
 
    
    gtk_box_pack_start(GTK_BOX(box1),button,TRUE,TRUE,0);
 
    gtk_widget_show(button);
 
    gtk_widget_show(box1);
    
    gtk_widget_show(ImageBox);
 
//    gtk_widget_show(window);

    gtk_widget_show_all(window);

    //进入主循环
    gtk_main();
 
    return 0;
 
}

