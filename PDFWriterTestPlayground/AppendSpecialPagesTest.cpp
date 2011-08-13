/*
   Source File : AppendSpecialPagesTest.cpp


   Copyright 2011 Gal Kahana HummusPDFWriter

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

   
*/
#include "AppendSpecialPagesTest.h"
#include "TestsRunner.h"
#include "HummusPDFWriter.h"

#include <iostream>

using namespace std;

AppendSpecialPagesTest::AppendSpecialPagesTest(void)
{
}

AppendSpecialPagesTest::~AppendSpecialPagesTest(void)
{
}

EPDFStatusCode AppendSpecialPagesTest::Run()
{
	EPDFStatusCode status;
	HummusPDFWriter pdfWriter;

	do
	{

		status = pdfWriter.StartPDF("C:\\PDFLibTests\\AppendSpecialPagesTest.PDF",ePDFVersion13,LogConfiguration(true,true,"c:\\pdflibtests\\AppendSpecialPagesTestLog.txt"));
		if(status != ePDFSuccess)
		{
			cout<<"failed to start PDF\n";
			break;
		}	

		EPDFStatusCodeAndObjectIDTypeList result;

		result = pdfWriter.AppendPDFPagesFromPDF("C:\\PDFLibTests\\TestMaterials\\Protected.pdf",PDFPageRange());
		if(result.first == ePDFSuccess)
		{
			cout<<"failted to NOT ALLOW embedding of protected documents\n";
			status = ePDFFailure;
			break;
		}

		result = pdfWriter.AppendPDFPagesFromPDF("C:\\PDFLibTests\\TestMaterials\\ObjectStreamsModified.pdf",PDFPageRange());
		if(result.first != ePDFSuccess)
		{
			cout<<"failed to append pages from ObjectStreamsModified.pdf\n";
			status = result.first;
			break;
		}

		result = pdfWriter.AppendPDFPagesFromPDF("C:\\PDFLibTests\\TestMaterials\\ObjectStreams.pdf",PDFPageRange());
		if(result.first != ePDFSuccess)
		{
			cout<<"failed to append pages from ObjectStreams.pdf\n";
			status = result.first;
			break;
		}

		
		result = pdfWriter.AppendPDFPagesFromPDF("C:\\PDFLibTests\\TestMaterials\\AddedItem.pdf",PDFPageRange());
		if(result.first != ePDFSuccess)
		{
			cout<<"failed to append pages from AddedItem.pdf\n";
			status = result.first;
			break;
		}

		result = pdfWriter.AppendPDFPagesFromPDF("C:\\PDFLibTests\\TestMaterials\\AddedPage.pdf",PDFPageRange());
		if(result.first != ePDFSuccess)
		{
			cout<<"failed to append pages from AddedPage.pdf\n";
			status = result.first;
			break;
		}


		result = pdfWriter.AppendPDFPagesFromPDF("C:\\PDFLibTests\\TestMaterials\\MultipleChange.pdf",PDFPageRange());
		if(result.first != ePDFSuccess)
		{
			cout<<"failed to append pages from MultipleChange.pdf\n";
			status = result.first;
			break;
		}

		result = pdfWriter.AppendPDFPagesFromPDF("C:\\PDFLibTests\\TestMaterials\\RemovedItem.pdf",PDFPageRange());
		if(result.first != ePDFSuccess)
		{
			cout<<"failed to append pages from RemovedItem.pdf\n";
			status = result.first;
			break;
		}


		result = pdfWriter.AppendPDFPagesFromPDF("C:\\PDFLibTests\\TestMaterials\\Linearized.pdf",PDFPageRange());
		if(result.first != ePDFSuccess)
		{
			cout<<"failed to append pages from RemovedItem.pdf\n";
			status = result.first;
			break;
		}

		status = pdfWriter.EndPDF();
		if(status != ePDFSuccess)
		{
			cout<<"failed in end PDF\n";
			break;
		}

	}while(false);

	return status;
}

ADD_CATEGORIZED_TEST(AppendSpecialPagesTest,"PDFEmbedding")