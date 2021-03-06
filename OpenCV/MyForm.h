#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
namespace OpenCV {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace cv;
	using namespace std;

	Mat image, src,dst;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::PictureBox^  ptbSrc;


	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;


	private: System::Windows::Forms::TrackBar^  elementTrackbar;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TrackBar^  sizeTrackbar;

	private: System::Windows::Forms::PictureBox^  ptb_process;
	private: System::Windows::Forms::RadioButton^  radioDilate;
	private: System::Windows::Forms::RadioButton^  radioErosi;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  openingRadio;
	private: System::Windows::Forms::RadioButton^  closingRadio;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  ElementLabel;


	private: System::Windows::Forms::Label^  kernelLabel;

	private: System::Windows::Forms::RadioButton^  radioBlur;
	private: System::Windows::Forms::RadioButton^  gaussianRadio;
	private: System::Windows::Forms::RadioButton^  radioSobel;
	private: System::Windows::Forms::RadioButton^  radioCanny;
	private: System::Windows::Forms::RadioButton^  radioLaplas;
	private: System::Windows::Forms::RadioButton^  radioScahrr;








	protected:

	private:
		/// <summary>
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->ptbSrc = (gcnew System::Windows::Forms::PictureBox());
			this->elementTrackbar = (gcnew System::Windows::Forms::TrackBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->sizeTrackbar = (gcnew System::Windows::Forms::TrackBar());
			this->ptb_process = (gcnew System::Windows::Forms::PictureBox());
			this->radioDilate = (gcnew System::Windows::Forms::RadioButton());
			this->radioErosi = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->openingRadio = (gcnew System::Windows::Forms::RadioButton());
			this->closingRadio = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->ElementLabel = (gcnew System::Windows::Forms::Label());
			this->kernelLabel = (gcnew System::Windows::Forms::Label());
			this->radioBlur = (gcnew System::Windows::Forms::RadioButton());
			this->gaussianRadio = (gcnew System::Windows::Forms::RadioButton());
			this->radioSobel = (gcnew System::Windows::Forms::RadioButton());
			this->radioCanny = (gcnew System::Windows::Forms::RadioButton());
			this->radioLaplas = (gcnew System::Windows::Forms::RadioButton());
			this->radioScahrr = (gcnew System::Windows::Forms::RadioButton());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ptbSrc))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->elementTrackbar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sizeTrackbar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ptb_process))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(650, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->openToolStripMenuItem });
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutToolStripMenuItem });
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::aboutToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// ptbSrc
			// 
			this->ptbSrc->Location = System::Drawing::Point(8, 26);
			this->ptbSrc->Name = L"ptbSrc";
			this->ptbSrc->Size = System::Drawing::Size(272, 222);
			this->ptbSrc->TabIndex = 1;
			this->ptbSrc->TabStop = false;
			// 
			// elementTrackbar
			// 
			this->elementTrackbar->LargeChange = 1;
			this->elementTrackbar->Location = System::Drawing::Point(2, 317);
			this->elementTrackbar->Maximum = 2;
			this->elementTrackbar->Name = L"elementTrackbar";
			this->elementTrackbar->Size = System::Drawing::Size(131, 45);
			this->elementTrackbar->TabIndex = 20;
			this->elementTrackbar->Scroll += gcnew System::EventHandler(this, &MyForm::elementTrackbar_Scroll);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(5, 253);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 13);
			this->label1->TabIndex = 21;
			this->label1->Text = L"Size SE";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(7, 301);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(68, 13);
			this->label2->TabIndex = 22;
			this->label2->Text = L"Element Size";
			// 
			// sizeTrackbar
			// 
			this->sizeTrackbar->Location = System::Drawing::Point(1, 269);
			this->sizeTrackbar->Maximum = 20;
			this->sizeTrackbar->Name = L"sizeTrackbar";
			this->sizeTrackbar->Size = System::Drawing::Size(132, 45);
			this->sizeTrackbar->TabIndex = 23;
			this->sizeTrackbar->Scroll += gcnew System::EventHandler(this, &MyForm::sizeTrackbar_Scroll);
			// 
			// ptb_process
			// 
			this->ptb_process->Location = System::Drawing::Point(288, 27);
			this->ptb_process->Name = L"ptb_process";
			this->ptb_process->Size = System::Drawing::Size(272, 222);
			this->ptb_process->TabIndex = 24;
			this->ptb_process->TabStop = false;
			// 
			// radioDilate
			// 
			this->radioDilate->AutoSize = true;
			this->radioDilate->Location = System::Drawing::Point(6, 65);
			this->radioDilate->Name = L"radioDilate";
			this->radioDilate->Size = System::Drawing::Size(50, 17);
			this->radioDilate->TabIndex = 25;
			this->radioDilate->Text = L"Dilasi";
			this->radioDilate->UseVisualStyleBackColor = true;
			// 
			// radioErosi
			// 
			this->radioErosi->AutoSize = true;
			this->radioErosi->Location = System::Drawing::Point(6, 42);
			this->radioErosi->Name = L"radioErosi";
			this->radioErosi->Size = System::Drawing::Size(48, 17);
			this->radioErosi->TabIndex = 26;
			this->radioErosi->Text = L"Erosi";
			this->radioErosi->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(6, 19);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(58, 17);
			this->radioButton1->TabIndex = 27;
			this->radioButton1->Text = L"Normal";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// openingRadio
			// 
			this->openingRadio->AutoSize = true;
			this->openingRadio->Location = System::Drawing::Point(88, 19);
			this->openingRadio->Name = L"openingRadio";
			this->openingRadio->Size = System::Drawing::Size(65, 17);
			this->openingRadio->TabIndex = 28;
			this->openingRadio->Text = L"Opening";
			this->openingRadio->UseVisualStyleBackColor = true;
			// 
			// closingRadio
			// 
			this->closingRadio->AutoSize = true;
			this->closingRadio->Location = System::Drawing::Point(88, 42);
			this->closingRadio->Name = L"closingRadio";
			this->closingRadio->Size = System::Drawing::Size(59, 17);
			this->closingRadio->TabIndex = 29;
			this->closingRadio->Text = L"Closing";
			this->closingRadio->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Controls->Add(this->closingRadio);
			this->groupBox1->Controls->Add(this->radioErosi);
			this->groupBox1->Controls->Add(this->openingRadio);
			this->groupBox1->Controls->Add(this->radioDilate);
			this->groupBox1->Location = System::Drawing::Point(145, 255);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(159, 92);
			this->groupBox1->TabIndex = 30;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Morphology";
			// 
			// ElementLabel
			// 
			this->ElementLabel->AutoSize = true;
			this->ElementLabel->Location = System::Drawing::Point(81, 301);
			this->ElementLabel->Name = L"ElementLabel";
			this->ElementLabel->Size = System::Drawing::Size(13, 13);
			this->ElementLabel->TabIndex = 31;
			this->ElementLabel->Text = L"0";
			// 
			// kernelLabel
			// 
			this->kernelLabel->AutoSize = true;
			this->kernelLabel->Location = System::Drawing::Point(81, 255);
			this->kernelLabel->Name = L"kernelLabel";
			this->kernelLabel->Size = System::Drawing::Size(13, 13);
			this->kernelLabel->TabIndex = 32;
			this->kernelLabel->Text = L"0";
			// 
			// radioBlur
			// 
			this->radioBlur->AutoSize = true;
			this->radioBlur->Location = System::Drawing::Point(334, 278);
			this->radioBlur->Name = L"radioBlur";
			this->radioBlur->Size = System::Drawing::Size(43, 17);
			this->radioBlur->TabIndex = 34;
			this->radioBlur->TabStop = true;
			this->radioBlur->Text = L"Blur";
			this->radioBlur->UseVisualStyleBackColor = true;
			// 
			// gaussianRadio
			// 
			this->gaussianRadio->AutoSize = true;
			this->gaussianRadio->Location = System::Drawing::Point(334, 301);
			this->gaussianRadio->Name = L"gaussianRadio";
			this->gaussianRadio->Size = System::Drawing::Size(90, 17);
			this->gaussianRadio->TabIndex = 35;
			this->gaussianRadio->TabStop = true;
			this->gaussianRadio->Text = L"Gaussian Blur";
			this->gaussianRadio->UseVisualStyleBackColor = true;
			// 
			// radioSobel
			// 
			this->radioSobel->AutoSize = true;
			this->radioSobel->Location = System::Drawing::Point(334, 255);
			this->radioSobel->Name = L"radioSobel";
			this->radioSobel->Size = System::Drawing::Size(52, 17);
			this->radioSobel->TabIndex = 36;
			this->radioSobel->TabStop = true;
			this->radioSobel->Text = L"Sobel";
			this->radioSobel->UseVisualStyleBackColor = true;
			// 
			// radioCanny
			// 
			this->radioCanny->AutoSize = true;
			this->radioCanny->Location = System::Drawing::Point(439, 255);
			this->radioCanny->Name = L"radioCanny";
			this->radioCanny->Size = System::Drawing::Size(55, 17);
			this->radioCanny->TabIndex = 37;
			this->radioCanny->TabStop = true;
			this->radioCanny->Text = L"Canny";
			this->radioCanny->UseVisualStyleBackColor = true;
			// 
			// radioLaplas
			// 
			this->radioLaplas->AutoSize = true;
			this->radioLaplas->Location = System::Drawing::Point(437, 279);
			this->radioLaplas->Name = L"radioLaplas";
			this->radioLaplas->Size = System::Drawing::Size(71, 17);
			this->radioLaplas->TabIndex = 38;
			this->radioLaplas->TabStop = true;
			this->radioLaplas->Text = L"Laplacian";
			this->radioLaplas->UseVisualStyleBackColor = true;
			// 
			// radioScahrr
			// 
			this->radioScahrr->AutoSize = true;
			this->radioScahrr->Location = System::Drawing::Point(437, 301);
			this->radioScahrr->Name = L"radioScahrr";
			this->radioScahrr->Size = System::Drawing::Size(56, 17);
			this->radioScahrr->TabIndex = 39;
			this->radioScahrr->TabStop = true;
			this->radioScahrr->Text = L"Scharr";
			this->radioScahrr->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(650, 350);
			this->Controls->Add(this->radioScahrr);
			this->Controls->Add(this->radioLaplas);
			this->Controls->Add(this->radioCanny);
			this->Controls->Add(this->radioSobel);
			this->Controls->Add(this->gaussianRadio);
			this->Controls->Add(this->radioBlur);
			this->Controls->Add(this->kernelLabel);
			this->Controls->Add(this->ElementLabel);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->ptbSrc);
			this->Controls->Add(this->ptb_process);
			this->Controls->Add(this->sizeTrackbar);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->elementTrackbar);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ptbSrc))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->elementTrackbar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sizeTrackbar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ptb_process))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

		openFileDialog1->InitialDirectory = "D:\\";
		openFileDialog1->Filter = "Bitmap Files(*.bmp) |*.bmp| JPEG(*.jpg;*.jpeg;*.jpe;*.jfif) | *.jpg;*.jpeg;*.jpe;*.jfif | GIF(*.gif) | *.gif | PNG(*.png) | *.png | All Files|*.*";
		openFileDialog1->FilterIndex = 5;
		
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel)
		{
			return;
		}

		src = toResize(imread(ConvertString2Char(openFileDialog1->FileName))); // resize image
		Mat imgSrc, erosionImg, dilateImg, openingImg, closingImg, blurImg,sobelImg,cannyImg,gaussianBlurImg,scharrImg;
	
		erosionImg = src;
		dilateImg = src;
		openingImg = src;
		closingImg = src;
		blurImg = src;
		sobelImg = src;
		imgSrc = src;
		cannyImg = src;
		scharrImg = src;
		gaussianBlurImg = src;
		if (radioDilate->Checked) {
			DrawCVImage(ptb_process, dilateImg);
			DrawCVImage(ptbSrc, imgSrc);
		}
		else if (radioErosi->Checked) {
			DrawCVImage(ptb_process, erosionImg);
			DrawCVImage(ptbSrc, imgSrc);
		}
		else if (openingRadio->Checked) {
			DrawCVImage(ptb_process, openingImg);
			DrawCVImage(ptbSrc, imgSrc);
		}
		else if (closingRadio->Checked) {
			DrawCVImage(ptb_process, closingImg);
			DrawCVImage(ptbSrc, imgSrc);
		}
		else if (radioSobel->Checked) {
			DrawCVImage(ptb_process, sobelImg);
			DrawCVImage(ptbSrc, imgSrc);
		}
		else if (radioBlur->Checked) {
			DrawCVImage(ptb_process, blurImg);
			DrawCVImage(ptbSrc, imgSrc);
		}
		else if (radioLaplas->Checked) {
			DrawCVImage(ptb_process, blurImg);
			DrawCVImage(ptbSrc, imgSrc);
		}
		else if (gaussianRadio->Checked) {
			DrawCVImage(ptb_process, gaussianBlurImg);
			DrawCVImage(ptbSrc, imgSrc);
		}
		else if (radioCanny->Checked) {
			DrawCVImage(ptb_process, cannyImg);
			DrawCVImage(ptbSrc, imgSrc);
		}
		else if (radioScahrr->Checked) {
			DrawCVImage(ptb_process, scharrImg);
			DrawCVImage(ptbSrc, imgSrc);
		}
		else {
			DrawCVImage(ptbSrc, imgSrc);
			DrawCVImage(ptb_process, imgSrc);
		}
	}
	
private: char* ConvertString2Char(System::String^ str) {
	char* str2 = (char*)(void*)Marshal::StringToHGlobalAnsi(str);
	return str2;	
}

private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}

private: cv::Mat toErotion(Mat src) {

	int erosion_elem = elementTrackbar->Value;
	int erosion_size = sizeTrackbar->Value;
	int erosion_type;

	if (erosion_elem == 0) { erosion_type = MORPH_RECT; }
	else if (erosion_elem == 1) { erosion_type = MORPH_CROSS; }
	else if (erosion_elem == 2) { erosion_type = MORPH_ELLIPSE; }

	Mat element = getStructuringElement(erosion_type,
		cv::Size(2 * erosion_size + 1, 2 * erosion_size + 1),
		cv::Point(erosion_size, erosion_size));
	
	erode(src, dst, element);
	return dst;
}

private: cv::Mat toDilate(Mat src) {
	
	elementTrackbar->Maximum = 2;
	int dilation_elem = elementTrackbar->Value;
	int dilation_size = sizeTrackbar->Value;
	int dilation_type;
	
	if (dilation_elem == 0) { dilation_type = MORPH_RECT; }
	else if (dilation_elem == 1) { dilation_type = MORPH_CROSS; }
	else if (dilation_elem == 2) { dilation_type = MORPH_ELLIPSE; }

	Mat element = getStructuringElement(dilation_type,
		cv::Size(2 * dilation_size + 1, 2 * dilation_size + 1),
		cv::Point(dilation_size, dilation_size));
	/// Apply the dilation operation
	dilate(src, dst, element);

	return dst;
}

private: cv::Mat toOpening(Mat src) {

	int element_size = elementTrackbar->Value;
	int closing_size = sizeTrackbar->Value;
	int type;

	if (element_size == 0) { type = MORPH_RECT; }
	else if (element_size == 1) { type = MORPH_CROSS; }
	else if (element_size == 2) { type = MORPH_ELLIPSE; }

	Mat element = getStructuringElement(type,
		cv::Size(2 * closing_size + 1, 2 * closing_size + 1),
		cv::Point(closing_size, closing_size));

	morphologyEx(src, dst, MORPH_OPEN, element);

	return dst;
}

private: cv::Mat toBlurFilter(Mat src) {
	blur(src, dst, cv::Size(sizeTrackbar->Value, sizeTrackbar->Value));
	return dst;
}

private: cv::Mat toGaussianBlur(Mat src) {
	GaussianBlur(src, dst, cv::Size(sizeTrackbar->Value, sizeTrackbar->Value), 0,0);
	return dst;
}
private: cv::Mat toSobel(Mat src) {
	Mat sobelDst;
	Sobel(src, dst, CV_16S, sizeTrackbar->Value, 1);
	convertScaleAbs(dst, sobelDst);
	return sobelDst;
}
private: cv::Mat LaplasFilter(Mat src) {
	Mat laplasDst;
	Laplacian(src, dst, CV_16S, sizeTrackbar->Value,1,0);
	convertScaleAbs(dst, laplasDst);
	return laplasDst;
}

private: cv::Mat toScharr(Mat src) {
	Scharr(src, dst, CV_SCHARR,0,1);

	return dst;
}
private: cv::Mat CannyFilter(Mat src) {
	Mat dst1, dst2;
	cvtColor(src, dst, CV_BGR2GRAY);
	GaussianBlur(dst, dst, cv::Size(sizeTrackbar->Value, sizeTrackbar->Value), 2);
	double t1 = 30, t2 = 200;
	Canny(dst, dst1, t1, t2, 3, false);
	convertScaleAbs(dst1, dst2);
	return dst2;
}
private: cv::Mat toClosing(Mat src) {
	int element_size = elementTrackbar->Value;
	int closing_size = sizeTrackbar->Value;
	int type;

	if (element_size == 0) { type = MORPH_RECT; }
	else if (element_size == 1) { type = MORPH_CROSS; }
	else if (element_size == 2) { type = MORPH_ELLIPSE; }

	Mat element = getStructuringElement(type,
		cv::Size(2 * closing_size + 1, 2 * closing_size + 1),
		cv::Point(closing_size, closing_size));

	morphologyEx(src, dst, MORPH_CLOSE, element);

	return dst;
}

private: Mat toResize(Mat src) {
		Mat dst;
		resize(src, dst, cv::Size(320, 240), 0, 0, 1);
		return dst;
}

private: void DrawCVImage(System::Windows::Forms::Control^control, cv::Mat& colorImage) {
		System::Drawing::Graphics^ graphics = control->CreateGraphics();
		System::IntPtr ptr(colorImage.ptr());
		System::Drawing::Bitmap^ b;
		
		switch (colorImage.type())
		{
		case CV_8UC3:
			b = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step, 
				System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
			break;
		case CV_8UC1:
			b = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step, 
				System::Drawing::Imaging::PixelFormat::Format8bppIndexed, ptr);
			break;
		default:
			b = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step,
				System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
			break;
		}

		System::Drawing::RectangleF rect(0, 0, (float)control->Width, (float)control->Height);
		graphics->DrawImage(b, rect);
	
}
private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	MessageBox::Show("Library : OPENCV \nDeveloper : Ibnu Ali");
}

private: System::Void elementTrackbar_Scroll(System::Object^  sender, System::EventArgs^  e) {
	if (radioErosi->Checked) {
		DrawCVImage(ptb_process, toErotion(src));
		ElementLabel->Text = elementTrackbar->Value.ToString();
	}
	else if (radioDilate->Checked) {
		DrawCVImage(ptb_process, toDilate(src));
		ElementLabel->Text = elementTrackbar->Value.ToString();
	}
	else if (openingRadio->Checked) {
		DrawCVImage(ptb_process, toOpening(src));
		ElementLabel->Text = elementTrackbar->Value.ToString();
	}
	else if (closingRadio->Checked) {
		DrawCVImage(ptb_process, toClosing(src));
		ElementLabel->Text = elementTrackbar->Value.ToString();
	}
	else {
		ElementLabel->Text = elementTrackbar->Value.ToString();
	}
}
private: System::Void sizeTrackbar_Scroll(System::Object^  sender, System::EventArgs^  e) {
	sizeTrackbar->Maximum = 20;
	if (radioErosi->Checked) {
		DrawCVImage(ptb_process, toErotion(src));
		kernelLabel->Text = sizeTrackbar->Value.ToString();
	}
	else if (radioDilate->Checked) {
		DrawCVImage(ptb_process, toDilate(src));
		kernelLabel->Text = sizeTrackbar->Value.ToString();
	}
	else if (openingRadio->Checked) {
		DrawCVImage(ptb_process, toOpening(src));
		kernelLabel->Text = sizeTrackbar->Value.ToString();
	}
	else if (closingRadio->Checked) {
		DrawCVImage(ptb_process, toClosing(src));
		kernelLabel->Text = sizeTrackbar->Value.ToString();
	}
	else if (radioBlur->Checked && sizeTrackbar->Value != 0) {
		DrawCVImage(ptb_process, toBlurFilter(src));
		kernelLabel->Text = sizeTrackbar->Value.ToString();
	}
	else if (radioSobel->Checked) {
		sizeTrackbar->Maximum = 2;
		DrawCVImage(ptb_process, toSobel(src));
		kernelLabel->Text = sizeTrackbar->Value.ToString();
	}
	else if (radioCanny->Checked && sizeTrackbar->Value%2 ==1) {
		DrawCVImage(ptb_process, CannyFilter(src));
		kernelLabel->Text = sizeTrackbar->Value.ToString();
	}
	else if (gaussianRadio->Checked && sizeTrackbar->Value % 2 == 1) {
		DrawCVImage(ptb_process, toGaussianBlur(src));
		kernelLabel->Text = sizeTrackbar->Value.ToString();
	}
	else if (radioLaplas->Checked &&  sizeTrackbar->Value % 2 == 1) {
		DrawCVImage(ptb_process, LaplasFilter(src));
		kernelLabel->Text = sizeTrackbar->Value.ToString();
	}
	else if (radioScahrr->Checked) {
		DrawCVImage(ptb_process, toScharr(src));
		kernelLabel->Text = sizeTrackbar->Value.ToString();
	}
	else {
		kernelLabel->Text = sizeTrackbar->Value.ToString();
	}
}
};
}
