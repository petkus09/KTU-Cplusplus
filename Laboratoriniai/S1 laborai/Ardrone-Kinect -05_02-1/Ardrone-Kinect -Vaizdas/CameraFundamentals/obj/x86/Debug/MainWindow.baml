   M S B A M L   `   `   `  ����  MotionKinect#    CameraFundamentals.MainWindow   5   	   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   -   5          � Title$  Pagrindinis langas��5   	   $	��884��6$   $
��1049��61    � WindowStyle$ 
ToolWindow=�6l    � WindowStartupLocation$ CenterScreen=�6�    � 
ResizeMode$ NoResize=�6�    � WindowState$ 	Maximized=�6�   .��5      � 
���   � � ColumnDefinitions 5   
   �� 5      $
��278* �6   �� 5      $
��749* �6   .+�5
   
   �� -   5         ��Name$ image3��5
      $
��Fill=�6    $��2��6/   $��
0,46,0,-46q�6C   �� 5   
   -   5         ��Name$ label2��5   g   $��Gaunama komanda...��6   $��28��6-   $
��Left=�69   $��	94,12,0,0q�6T   $	��Top=�6w   $	��320��6�   
�������$��1��6�   $y�Hidden=�6�   �� 5   
   -   5        $ image2��5   K   $	��240��6   $
��Left=�6   $��	94,46,0,0q�68   $
��Fill=�6[   $	��Top=�6j   $	��320��6�   $	��320��6�   $	��240��6�   $��1��6�   �� 5   
   -   5        $ image1��5   K   $	��240��6   $
��Left=�6   $��	32,46,0,0q�68   $
��Fill=�6[   $	��Top=�6j   $	��320��6�   $	��320��6�   $	��240��6�   $��2��6�   �� 5   
   -   5        $ label1��5   _   $��
Komanda...��6   $��28��6%   $
��Left=�61   $��	32,12,0,0q�6L   $	��Top=�6o   $	��320��6�   
�������$��2��6�   $y�Hidden=�6�   �� 5   
   -   5         ��Name$ Skeleton��5      $��0,210,707,412q�6#   $	��320��6:   $	��240��6I   $��2��6Y   6o   �� 5   
   -   5        $��image8��5   L   $��12��6   $
��Left=�6   $��647,310,0,0q�67   $��Uniform=�6Z   $	��Top=�6l   $��80��6�   $y�Hidden=�6�   $,��&/MotionKinect;component/Images/m13.png��6�   $��1��6�   �� 5   
   -	   5        $��image15��5   K   $��4��6   $
��Left=�6   $��647,328,0,0q�66   $,��&/MotionKinect;component/Images/m15.png��6Z   $��Uniform=�6�   $	��Top=�6�   $y�Hidden=�6�   $��80��6�   $��1��6�   �� 5   
   -
   5        $��image16��5   L   $��15��6   $
��Left=�6   $��647,338,0,0q�67   $,��&/MotionKinect;component/Images/m14.png��6[   $��Uniform=�6�   $	��Top=�6�   $y�Hidden=�6�   $��80��6�   $��1��6�   �� 5   
   -   5        $��image9��5   L   $��29��6   $
��Left=�6   $��527,195,0,0q�67   $��Uniform=�6Z   $	��Top=�6l   $	��200��6�   $y�Hidden=�6�   $,��&/MotionKinect;component/Images/m13.png��6�   $��1��6�   �� 5   
   -   5        $��image11��5   L   $��25��6   $
��Left=�6   $��557,230,0,0q�67   $��Uniform=�6[   $	��Top=�6m   $	��170��6�   $y�Hidden=�6�   $,��&/MotionKinect;component/Images/m13.png��6�   $��1��6�   �� 5   
   -   5        $��image12��5   L   $��20��6   $
��Left=�6   $��587,261,0,0q�67   $��Uniform=�6[   $	��Top=�6m   $	��140��6�   $y�Hidden=�6�   $,��&/MotionKinect;component/Images/m13.png��6�   $��1��6�   �� 5   
   -   5        $��image10��5   L   $��17��6   $
��Left=�6   $��617,287,0,0q�67   $��Uniform=�6[   $	��Top=�6m   $	��110��6�   $y�Hidden=�6�   $,��&/MotionKinect;component/Images/m13.png��6�   $��1��6�   �� 5   
   -   5        $��image6��5   J   $��57��6   $
��Left=�6   $��	30,13,0,0q�67   $��Uniform=�6X   $	��Top=�6j   $��58��6�   $y�Hidden=�6�   $��1��6�   �� 5   
   -   5        $��image5��5   K   $��57��6   $
��Left=�6   $��
212,13,0,0q�67   $��Uniform=�6Y   $	��Top=�6k   $��58��6�   $y�Hidden=�6�   �� 5   
   -   5        $��image4��5   K   $��57��6   $
��Left=�6   $��
123,13,0,0q�67   $��Uniform=�6Y   $	��Top=�6k   $��58��6�   $y�Hidden=�6�   �� 5   
   -   5        $��image14��5   J   $��57��6   $
��Left=�6   $��	32,13,0,0q�67   $��Uniform=�6Y   $	��Top=�6k   $y�Hidden=�6�   $��58��6�   �� 5   
   -   5        $��image7��5   L   $��57��6   $��Right=�6   $��
0,13,569,0q�68   $��Uniform=�6Z   $	��Top=�6l   $��58��6�   $y�Hidden=�6�   $��1��6�   �� 5   
   -   5        $��image13��5   L   $	��101��6   $
��Left=�6   $��
22,563,0,0q�68   $��Uniform=�6[   $	��Top=�6m   $	��223��6�   $,��&/MotionKinect;component/Images/m11.png��6�   �� 5   
   -   5        $ labelgaz��5   �   $�� ��6   $
��Left=�6   $��
94,595,0,0q�66   $	��Top=�6J   
���   �$��32(�6u   $��78��6�   $��Times New Roman)�6�   $��38��6�   $��Normal&�6�   ��6�   Z� 6�   �� 5   
   -   5        $��image17��5      $	��135��6   $
��Fill=�6,   $	��531��6;   $,��&/MotionKinect;component/Images/m16.png��6G   $y�Hidden=�6w   $��2��6�   $��242,218,254,492q�6�   5      5       