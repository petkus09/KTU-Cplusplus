/////////////////////////////////////////////////////////////////////////
//
//
// Copyright (c) Microsoft Corporation. All rights reserved.
// This code is licensed under the terms of the Microsoft Kinect for
// Windows SDK (Beta) License Agreement:
// http://kinectforwindows.org/KinectSDK-ToU
//
/////////////////////////////////////////////////////////////////////////
using System;
using System.Diagnostics;
using System.Threading;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Threading;
using Microsoft.Kinect;
using Coding4Fun.Kinect.Wpf; 
//using System.Windows.Forms;  

namespace CameraFundamentals
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {

        private DispatcherTimer timerUpdate;
        private DispatcherTimer timerVideoUpdate;
        private DispatcherTimer timerColorUpdate;
        private DispatcherTimer timerDepthUpdate;
        private DispatcherTimer timerSkellUpdate;


        private NUIcontroler _nui;
        private DroneControler _drone;

        private KinectCanvas _kinectCanvas;

        private Timer _timer;
        private Timer _trotleft;
        private Timer _trotright;
        private Timer _tforward;
        private Timer _tbackward;
        private Timer _tflyleft;
        private Timer _tflyright;
        private Timer _takingOff;
        private Timer _tflyup;
        private Timer _tflydown;
        private Timer _tup;
        private Timer _tdown;
        private DispatcherTimer resetdroneimage;

        private bool takeOffCom;
        private bool conMassage;
        private bool islanding;
        private bool command;
        private bool motion;

        private bool imgNormal;
        private bool imgTakeOff;

        private Stopwatch stopWatch;

        private int gear = 1;
        private bool changegear = false;


        //=========================================================
        private const int takt = 3; 
        private long imgd = takt;
        private long imgp = takt;
        private long imgr = takt;
        private long imgg = takt;
        private long imgpap = takt;
        private bool poz = false;
        private float gazval = 0;
        //=========================================================




        public MainWindow()
        {
            WindowState = WindowState.Normal;
            WindowStyle = WindowStyle.None;
            Topmost = true;
            WindowState = WindowState.Maximized;
            stopWatch = new Stopwatch();
            takeOffCom = false;
            conMassage = false;
            islanding = false;
            command = false;
            motion = true;
            imgNormal = true;
            imgTakeOff = false;


            WindowState = WindowState.Normal;
            WindowStyle = WindowStyle.None;
            Topmost = true;
            WindowState = WindowState.Maximized;
            InitializeDrone();
            InitializeKinect();
            InitializeTimers();
        }

        
        
        private void InitializeDrone()
        {
            _drone = new DroneControler(ref label1);
            _drone.ConnectToNetwork();
        }

        private void InitializeKinect()
        {

            _nui = new NUIcontroler(800, 600);
            _nui.init();
            _kinectCanvas = new KinectCanvas(_nui);
        }

        private void InitializeTimers()
        {
            timerUpdate = new DispatcherTimer();
            timerUpdate.Interval = new TimeSpan(0, 0, 0, 0, 33);
            timerUpdate.Tick += new EventHandler(timerStatusUpdate_Tick);
            timerUpdate.Start();

            timerVideoUpdate = new DispatcherTimer();
            timerVideoUpdate.Interval = new TimeSpan(0, 0, 0, 0, 33);
            timerVideoUpdate.Tick += new EventHandler(timerVideoUpdate_Tick);
            timerVideoUpdate.Start();

            timerColorUpdate = new DispatcherTimer();
            timerColorUpdate.Interval = new TimeSpan(0, 0, 0, 0, 33);
            timerColorUpdate.Tick += new EventHandler(timerCUpdate_Tick);
            timerColorUpdate.Start();

            timerDepthUpdate = new DispatcherTimer();
            timerDepthUpdate.Interval = new TimeSpan(0, 0, 0, 0, 33);
            timerDepthUpdate.Tick += new EventHandler(timerDUpdate_Tick);
            timerDepthUpdate.Start();

            timerSkellUpdate = new DispatcherTimer();
            timerSkellUpdate.Interval = new TimeSpan(0, 0, 0, 0, 100);
            timerSkellUpdate.Tick += new EventHandler(timerSUpdate_Tick);
            timerSkellUpdate.Start();

            resetdroneimage = new DispatcherTimer();
            resetdroneimage.Interval = new TimeSpan(0, 1, 0);
            resetdroneimage.Tick += new EventHandler(reset_tick);
            resetdroneimage.Start();
        }

        private void reset_tick(object sender, EventArgs e)
        {
            if (_drone.droneControl.IsConnected)
            {
               
            }
        }

        private void UpdateStatus()
        {
            stopWatch.Stop();
            float gameTime = stopWatch.Elapsed.Milliseconds;
            stopWatch.Reset();
            stopWatch.Start();

            if (motion)
            {
                UpdateMotion(gameTime);
            }
            else
            {
                UpdateVoice();
            }

          
        }


        private void SkeletonDraw()
        { 
            if (_nui.skelet != null)
            {
                Skeleton.Children.Clear();
                //PaintBones(_nui.skelet);
                //PaintJoints(_nui.skelet);
            }
            else
            {
                Skeleton.Children.Clear();
            }

        }

        private void PaintJoints(Skeleton skeleton)
        {
            foreach (Joint joint in skeleton.Joints)
            {
                var jointPos = _kinectCanvas.GetDisplayPosition(joint);
                var jointLine = new Line
                {
                    X1 = jointPos.X - 3
                };
                jointLine.X2 = jointLine.X1 + 8;
                jointLine.Y1 = jointLine.Y2 = jointPos.Y;
                jointLine.Stroke = KinectCanvas.JointColors[joint.JointType];
                jointLine.StrokeThickness = 8;
                Skeleton.Children.Add(jointLine);
            }
        }

        private void PaintBones(Skeleton skeleton)
        {
         
            var brush = new SolidColorBrush(Colors.Blue);
            Skeleton.Children.Add(_kinectCanvas.GetBodySegment
                (skeleton.Joints, brush, JointType.HipCenter,
                JointType.Spine, JointType.ShoulderCenter, JointType.Head));
            Skeleton.Children.Add(_kinectCanvas.GetBodySegment
                (skeleton.Joints, brush, JointType.ShoulderCenter,
                JointType.ShoulderLeft, JointType.ElbowLeft, JointType.WristLeft, JointType.HandLeft));
            Skeleton.Children.Add(_kinectCanvas.GetBodySegment
                (skeleton.Joints, brush, JointType.ShoulderCenter,
                JointType.ShoulderRight, JointType.ElbowRight, JointType.WristRight, JointType.HandRight));
            Skeleton.Children.Add(_kinectCanvas.GetBodySegment
                (skeleton.Joints, brush, JointType.HipCenter, JointType.HipLeft,
                JointType.KneeLeft, JointType.AnkleLeft, JointType.FootLeft));
            Skeleton.Children.Add(_kinectCanvas.GetBodySegment
                (skeleton.Joints, brush, JointType.HipCenter, JointType.HipRight,
                JointType.KneeRight, JointType.AnkleRight, JointType.FootRight));
        }



        private void UpdateVoice()
        {
            //label3.Content = "Sound: " + _nui.msg;
            if (_nui.voiceTakingOff && !_drone.droneControl.IsFlying)
            {
                _drone.Takeoff();
                _nui.voiceTakingOff = false;
                label1.Content = "Voice -> Take off";
                label2.Content = "Balsas - Pakilti";
            }
            if (_drone.droneControl.IsConnected && _drone.droneControl.IsFlying)
            {
                if (_nui.voiceLanding)
                {
                    _drone.Land();
                    label1.Content = "Voice -> Landing";
                    label2.Content = "Balsas - Nusileisti";
                    _nui.voiceLanding = false;
                } else if (_nui.voiceLeft)
                {
                    _drone.Navigate(0, 0, -0.5f, 0);
                    label1.Content = "Voice -> Rot Left";
                    label2.Content = "Balsas - Pasisukti Kairėn";
                    _nui.voiceLeft = false;
                } else if (_nui.voiceRight)
                {
                    _drone.Navigate(0, 0, 0.5f, 0);
                    label1.Content = "Voice -> Rot Right";
                    label2.Content = "Balsas - Pasisukti Desinėn";
                    _nui.voiceRight = false;
                } else if (_nui.voiceStop)
                {
                    _drone.Navigate(0, 0, 0, 0);
                    label1.Content = "Voice -> Stop";
                    label2.Content = "Balsas - Stop!";
                    _nui.voiceStop = false;
                }
            }
        }

        
        // judesiai ir drono elgesys
        private void UpdateMotion(float gameTime)
        {
            float gaz = Gaz() * gear / 10;
            float pitch = Pitch() * gear / 10;
            float disp = Disp() * gear / 10;
            float rot = Rotate() * gear / 10;
            if (poz)
            {
                gazval = (Math.Abs(gaz) + Math.Abs(pitch) + Math.Abs(disp)) / 3 * 100;
                labelgaz.Content = double.Parse(gazval.ToString("####0"));
            }

            imgd++;
            imgg++;
            imgp++;
            imgr++;
            imgpap++;

            if (imgg > takt)
            {
                image14.Visibility = Visibility.Hidden;
                imgg = takt;                 
            }
            if (imgp > takt)
            {
                image6.Visibility = Visibility.Hidden;
                imgp = takt;
            }
            if (imgd > takt)
            {
                image5.Visibility = Visibility.Hidden;
                imgd = takt;
            }
            if (imgr > takt)
            {
                image4.Visibility = Visibility.Hidden;
                imgr = takt;
            }
            if (imgpap > takt)
            {
                image7.Visibility = Visibility.Hidden;
                imgpap = takt;
            }


            if (gear == 0)
            {
                image8.Visibility = Visibility.Hidden;
                image9.Visibility = Visibility.Hidden;
                image10.Visibility = Visibility.Hidden;
                image11.Visibility = Visibility.Hidden;
                image12.Visibility = Visibility.Hidden;
                image15.Visibility = Visibility.Visible;
                image16.Visibility = Visibility.Hidden;
            }
            else
                if (gear == 1)
                {
                    image8.Visibility = Visibility.Visible;
                    image9.Visibility = Visibility.Hidden;
                    image10.Visibility = Visibility.Hidden;
                    image11.Visibility = Visibility.Hidden;
                    image12.Visibility = Visibility.Hidden;
                    image15.Visibility = Visibility.Visible;
                    image16.Visibility = Visibility.Hidden;
                }
                else
                    if (gear == 2)
                    {
                        image8.Visibility = Visibility.Visible;
                        image9.Visibility = Visibility.Hidden;
                        image10.Visibility = Visibility.Visible;
                        image11.Visibility = Visibility.Hidden;
                        image12.Visibility = Visibility.Hidden;
                        image15.Visibility = Visibility.Visible;
                        image16.Visibility = Visibility.Hidden;
                    }
                    else
                        if (gear == 3)
                        {
                            image8.Visibility = Visibility.Visible;
                            image9.Visibility = Visibility.Hidden;
                            image10.Visibility = Visibility.Visible;
                            image11.Visibility = Visibility.Hidden;
                            image12.Visibility = Visibility.Visible;
                            image15.Visibility = Visibility.Visible;
                            image16.Visibility = Visibility.Hidden;
                        }
                        else
                            if (gear == 4)
                            {
                                image8.Visibility = Visibility.Visible;
                                image9.Visibility = Visibility.Hidden;
                                image10.Visibility = Visibility.Visible;
                                image11.Visibility = Visibility.Visible;
                                image12.Visibility = Visibility.Visible;
                                image15.Visibility = Visibility.Visible;
                                image16.Visibility = Visibility.Hidden;
                            }
                            else
                                if (gear == 5)
                                {
                                    image8.Visibility = Visibility.Visible;
                                    image9.Visibility = Visibility.Visible;
                                    image10.Visibility = Visibility.Visible;
                                    image11.Visibility = Visibility.Visible;
                                    image12.Visibility = Visibility.Visible;
                                    image15.Visibility = Visibility.Visible;
                                    image16.Visibility = Visibility.Hidden;
                                }
                                else
                                    if (gear == -1)
                                    {  
                                        image8.Visibility = Visibility.Hidden;
                                        image9.Visibility = Visibility.Hidden;
                                        image10.Visibility = Visibility.Hidden;
                                        image11.Visibility = Visibility.Hidden;
                                        image12.Visibility = Visibility.Hidden;
                                        image15.Visibility = Visibility.Hidden;
                                        image16.Visibility = Visibility.Visible;
                                    }
           


           



            if (!_drone.droneControl.IsConnected && !_drone.droneControl.IsConnecting)
            {
                _drone.Connect();
            }
            if (_drone.droneControl.IsConnected)
            {
                if (!_drone.droneControl.IsFlying)
                {
                    updateTakeOff(gameTime);
                    label1.Content = "Not Flying; UpdateTakeOff";
                    label2.Content = "Laukiama";
                    label3.Visibility = Visibility.Visible;
                }

                if (!conMassage)
                {
                    conMassage = true;
                    _drone.FlatTrim();
                    label1.Content = "conMassage; FlatTrim";
                    label2.Content = "Stabilizuoti";
                }

                if (takeOffCom && !_drone.droneControl.IsFlying)
                {
                    label1.Content = "takeOffCom";
                    label2.Content = "Pakilti";
                    _drone.Takeoff();
                    takeOffCom = false;
                    islanding = false;
                    _takingOff = new Timer(1500);
                    poz = true;
                    image7.Source = new BitmapImage(new Uri(@"/MotionKinect;component/Images/m5.png", UriKind.Relative));
                    image7.Visibility = Visibility.Visible;
                    label3.Visibility = Visibility.Hidden;
                    imgpap = 0;
                    return;
                }
            }




            if (_drone.droneControl.IsFlying && takeOffCom == false)
            {
                if (KinectMotion.geardown(_nui.lhand, _nui.rhand, _nui.head) && !changegear)
                {
                    if (gear < 5)
                    {
                        gear++;
                    }
                    changegear = true;
                }
                if (KinectMotion.gearup(_nui.lhand, _nui.rhand, _nui.head) && !changegear)
                {
                    if (gear > -1)
                    {
                        gear--;
                    }
                    changegear = true;
                }
                if (!KinectMotion.geardown(_nui.lhand, _nui.rhand, _nui.head) && changegear && !KinectMotion.gearup(_nui.lhand, _nui.rhand, _nui.head))
                {
                    changegear = false;
                }
                if (KinectMotion.HandsDown(_nui.lhand, _nui.rhand, _nui.chip))
                {
                    label1.Content = "HandsDown";
                    _drone.Land();
                    islanding = true;
                    label2.Content = "Land";
                    poz = false;
                    gazval = 0;
                    labelgaz.Content = double.Parse(gazval.ToString("####0.00"));
                    return;
                }
            }

            if (_drone.droneControl.IsFlying && UpdateTimer(ref _takingOff, gameTime))
            {
                if (islanding == false && command == false)
                {
                    /*if (UpdateTimer(ref _tforward, gameTime))
                    {
                        _drone.Navigate(0, gaz, 0, 0);
                        command = true;
                    }
                    if (UpdateTimer(ref _tflyup, gameTime))
                    {

                        _drone.Navigate(0, 0, 0, pitch);
                        command = true;
                    }
                    if (UpdateTimer(ref _tflyleft, gameTime))
                    {
                        label1.Content = "Navigate";
                        label2.Content = "FlySomewhere";
                        _drone.Navigate(disp, 0, 0, 0);
                        command = true;
                    }
                    if (UpdateTimer(ref _trotleft, gameTime))
                    {

                        _drone.Navigate(0, 0, rot, 0);
                        command = true;
                    }*/
                    if (UpdateTimer(ref _tforward, gameTime))
                    {
                        _drone.Navigate(disp, gaz, rot, pitch);
                    }
                    return;
                }
                if (islanding == false && command == true)
                {
                    label1.Content = "Wait";
                    _drone.Navigate(0, 0, 0, 0);
                    command = false;
                }

            }
        }





            #region commented area
            //    if (_drone.droneControl.IsConnected)
        //    {
        //        if (Emergency())
        //        {
        //            _drone.Emergency();
        //            return;
        //        }
        //        if (!Land())
        //        {
        //            if (!_drone.droneControl.IsFlying)
        //            {
        //                if (_drone.droneControl.CanTakeoff)
        //                {
        //                    UpdateTimer(ref _takingOff, gameTime);
        //                    _drone.Takeoff();
        //                    return;
        //                }
        //            }
        //        }
        //        else
        //        {
        //            if (_drone.droneControl.IsFlying)
        //            {
        //                if (_drone.droneControl.CanLand)
        //                {
        //                    _drone.Land();
        //                    return;
        //                }
        //            }
        //        }
        //        if (UpdateTimer(ref _tbackward, gameTime))
        //        {
        //            _drone.Navigate(Disp(), Gaz(), Rotate(), Pitch());
        //        }

            //    }
            #endregion commented area
        

        private float Gaz()
        {
            float kint = KinectMotion.Gaz(_nui.lhand, _nui.rhand, _nui.lshoulder, _nui.rshoulder, _nui.cshoulder);

            if (poz && kint > 0.1)
            {
                image14.Source = new BitmapImage(new Uri(@"/MotionKinect;component/Images/m9.png", UriKind.Relative));
                imgg = 0;
                image14.Visibility = Visibility.Visible;
            }
            if (poz && kint < -0.1)
            {
                image14.Source = new BitmapImage(new Uri(@"/MotionKinect;component/Images/m8.png", UriKind.Relative));
                imgg = 0;
                image14.Visibility = Visibility.Visible;
            }
            return KinectMotion.Gaz(_nui.lhand, _nui.rhand, _nui.lshoulder, _nui.rshoulder, _nui.cshoulder);
        }

        private float Pitch()
        {
            float kint = KinectMotion.Pitch(_nui.lhand, _nui.rhand, _nui.lshoulder, _nui.rshoulder, _nui.cshoulder);
            if (poz && kint > 0.1)
            {
                image6.Source = new BitmapImage(new Uri(@"/MotionKinect;component/Images/m5.png", UriKind.Relative));
                imgp = 0;
                image6.Visibility = Visibility.Visible;
            }
            if (poz && kint < -0.1)
            {
                image6.Source = new BitmapImage(new Uri(@"/MotionKinect;component/Images/m4.png", UriKind.Relative));
                imgp = 0;
                image6.Visibility = Visibility.Visible;
            }
            return KinectMotion.Pitch(_nui.lhand, _nui.rhand, _nui.lshoulder, _nui.rshoulder, _nui.cshoulder);
        }

        private float Disp()
        {
            float kint = KinectMotion.Disp(_nui.lhand, _nui.rhand, _nui.lshoulder, _nui.rshoulder, _nui.cshoulder);
            if (poz && kint < -0.1)
            {
                image5.Source = new BitmapImage(new Uri(@"/MotionKinect;component/Images/m3.png", UriKind.Relative));
                imgd = 0;
                image5.Visibility = Visibility.Visible;
            }
            if (poz && kint > 0.1)
            {
                image5.Source = new BitmapImage(new Uri(@"/MotionKinect;component/Images/m2.png", UriKind.Relative));
                imgd = 0;
                image5.Visibility = Visibility.Visible;
            }
            return KinectMotion.Disp(_nui.lhand, _nui.rhand, _nui.lshoulder, _nui.rshoulder, _nui.cshoulder);
        }

        private float Rotate()
        {
            float kint = KinectMotion.Rotate(_nui.lhand, _nui.rhand, _nui.lshoulder, _nui.rshoulder, _nui.cshoulder);
            if (poz && kint < -0.1)
            {
                image4.Source = new BitmapImage(new Uri(@"/MotionKinect;component/Images/m7.png", UriKind.Relative));
                imgr = 0;
                image4.Visibility = Visibility.Visible;
            }
            if (poz && kint > 0.1)
            {
                image4.Source = new BitmapImage(new Uri(@"/MotionKinect;component/Images/m6.png", UriKind.Relative));
                imgr = 0;
                image4.Visibility = Visibility.Visible;
            }
            return KinectMotion.Rotate(_nui.lhand, _nui.rhand, _nui.lshoulder, _nui.rshoulder, _nui.cshoulder);
        }

        private bool Land()
        {
            image7.Source = new BitmapImage(new Uri(@"/MotionKinect;component/Images/m12.png", UriKind.Relative));
            image7.Visibility = Visibility.Visible;
            imgpap = 0;
            return KinectMotion.HandsDown(_nui.lhand, _nui.rhand, _nui.chip);
        }

        private bool Emergency()
        {
            image7.Source = new BitmapImage(new Uri(@"/MotionKinect;component/Images/m10.png", UriKind.Relative));
            image7.Visibility = Visibility.Visible;
            imgpap = 0;
            return KinectMotion.Emergency(_nui.lhand, _nui.rhand, _nui.head);
        }

        private bool UpdateTimer(ref Timer t, float gt)
        {
            if (t != null)
            {
                t.update(gt);
                if (t.finnish)
                    return true;
                else
                    return false;
            }
            else
            {
                t = new Timer(100);
                return false;
            }
        }

        private bool UpdateTimer(ref Timer t1, ref Timer t2, ref Timer t3, ref Timer t4, float gt)
        {
            if (t1 != null && t2!= null && t3 != null && t4 != null)
            {
                t1.update(gt);
                t2.update(gt);
                t3.update(gt);
                t4.update(gt);
                if (t1.finnish && t2.finnish && t3.finnish && t4.finnish)
                    return true;
                else
                    return false;
            }
            else
            {
                t1 = new Timer(750);
                t2 = new Timer(750);
                t3 = new Timer(750);
                t4 = new Timer(750);
                return false;
            }
        }
        private void updateTakeOff(float dt)
        {
            if (_nui.isSkeleton && !takeOffCom)
            {
                if (_timer == null)
                    _timer = new Timer(3000);
                else
                {
                    if (!KinectMotion.HandsDown(_nui.lhand, _nui.rhand, _nui.chip))
                    {
                        _timer.update(dt);
                        if (_timer.finnish)
                        {
                            takeOffCom = true;
                            _timer = null;
                        }
                    }
                    else
                        _timer = null;
                }
            }
        }


        private void SetNewDroidImage()
        {
            if (_drone.droneControl.ImageSourceImage != null) { }
               image3.Source = _drone.droneControl.ImageSourceImage;
        }

        private void timerStatusUpdate_Tick(object sender, EventArgs e)
        {

           
            label1.Content = _drone.msg;

            UpdateStatus();
            
        }

        private void timerSUpdate_Tick(object sender, EventArgs e)
        {
            //Title = _nui.FrameRate.ToString();
            SkeletonDraw();
        }

        private void timerDUpdate_Tick(object sender, EventArgs e)
        {
            //label1.Content = _drone.msg;
            if (_nui.depthBitmap != null && image1.Source == null)
            {
                //image1.Source = _nui.depthBitmap;
                timerDepthUpdate.Interval = new TimeSpan(0, 0, 0, 7, 0);
            }

        }

        private void timerCUpdate_Tick(object sender, EventArgs e)
        {
            //label1.Content = _drone.msg;
            //UpdateStatus();

            if (_nui.colorBitmap != null && image2.Source == null)
            {
                //image2.Source = _nui.colorBitmap;
                timerColorUpdate.Interval = new TimeSpan(0, 0, 0, 7, 0);
            }
        }
        
        private void timerVideoUpdate_Tick(object sender, EventArgs e)
        {
            SetNewDroidImage();
        }
        
        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            // per čia eina keist 'paveiksliukų' dydį
        }

        private void Window_Closed(object sender, EventArgs e)
        {
            _drone.Disconnect();
            _nui.StopKinect();
        }
        
        protected override void OnKeyDown(KeyEventArgs keyEvent)
        {
            if (keyEvent.Key == Key.V)
            {
             //   _nui.Start();
             //   motion = false;
             //   Title = "Balso sąsaja";
            }
            else if (keyEvent.Key == Key.M)
            {
             //   motion = true;
             //   Title = "Judesio sąsaja";
            }
            else if (keyEvent.Key == Key.Space)
            {
                if (_drone.droneControl.IsConnected)
                {
                    _drone.Land();
                    _drone.Disconnect();
                }
                _nui.StopKinect();
            }
        }

    }
}
