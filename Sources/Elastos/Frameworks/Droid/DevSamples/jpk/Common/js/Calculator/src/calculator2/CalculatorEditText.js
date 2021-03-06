module.exports = function(aoElastos, aoActivity){
//--------common definition----begin----
    var CObject = aoElastos.CObject;

    var CString = aoElastos.Core.CString;
    var Droid_New = aoElastos.Droid.New;
    var Core_New = aoElastos.Core.New;

    var R = aoElastos.Application.R;

    var oActivity = aoActivity.ActivityInstance;
    var oHandler = aoActivity.ActivityHandler;

    function CActivityListener(host) {
        this.mHost = host;
    }
    var _apt = CActivityListener.prototype;

    var IView__VISIBLE = 0x00000000;
    var IView__INVISIBLE = 0x00000004;
    var IView__GONE = 0x00000008;
    var IMotionEvent__ACTION_DOWN = 0;
    var IMotionEvent__ACTION_UP = 1;
    var IContext__LAYOUT_INFLATER_SERVICE = "layout_inflater";

//--------common definition----end----

//--------.java----begin----

/*
 * Copyright (C) 2014 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// package com.android.calculator2;

// import android.content.Context;
// import android.content.res.TypedArray;
// import android.graphics.Paint;
// import android.graphics.Paint.FontMetricsInt;
// import android.graphics.Rect;
// import android.os.Parcelable;
// import android.text.method.ScrollingMovementMethod;
// import android.text.TextPaint;
// import android.util.AttributeSet;
// import android.util.TypedValue;
// import android.view.ActionMode;
// import android.view.Menu;
// import android.view.MenuItem;
// import android.view.MotionEvent;
// import android.widget.EditText;
// import android.widget.TextView;

// public class CalculatorEditText extends EditText {

//     private final static ActionMode.Callback NO_SELECTION_ACTION_MODE_CALLBACK =
//             new ActionMode.Callback() {
//         @Override
//         public boolean onActionItemClicked(ActionMode mode, MenuItem item) {
//             return false;
//         }

//         @Override
//         public boolean onCreateActionMode(ActionMode mode, Menu menu) {
//             // Prevents the selection action mode on double tap.
//             return false;
//         }

//         @Override
//         public void onDestroyActionMode(ActionMode mode) {
//         }

//         @Override
//         public boolean onPrepareActionMode(ActionMode mode, Menu menu) {
//             return false;
//         }
//     };

//     private final float mMaximumTextSize;
//     private final float mMinimumTextSize;
//     private final float mStepTextSize;

//     // Temporary objects for use in layout methods.
//     private final Paint mTempPaint = new TextPaint();
//     private final Rect mTempRect = new Rect();

//     private int mWidthConstraint = -1;
//     private OnTextSizeChangeListener mOnTextSizeChangeListener;

//     public CalculatorEditText(Context context) {
//         this(context, null);
//     }

//     public CalculatorEditText(Context context, AttributeSet attrs) {
//         this(context, attrs, 0);
//     }

//     public CalculatorEditText(Context context, AttributeSet attrs, int defStyle) {
//         super(context, attrs, defStyle);

//         final TypedArray a = context.obtainStyledAttributes(
//                 attrs, R.styleable.CalculatorEditText, defStyle, 0);
//         mMaximumTextSize = a.getDimension(
//                 R.styleable.CalculatorEditText_maxTextSize, getTextSize());
//         mMinimumTextSize = a.getDimension(
//                 R.styleable.CalculatorEditText_minTextSize, getTextSize());
//         mStepTextSize = a.getDimension(R.styleable.CalculatorEditText_stepTextSize,
//                 (mMaximumTextSize - mMinimumTextSize) / 3);

//         a.recycle();

//         setCustomSelectionActionModeCallback(NO_SELECTION_ACTION_MODE_CALLBACK);
//         if (isFocusable()) {
//             setMovementMethod(ScrollingMovementMethod.getInstance());
//         }
//         setTextSize(TypedValue.COMPLEX_UNIT_PX, mMaximumTextSize);
//         setMinHeight(getLineHeight() + getCompoundPaddingBottom() + getCompoundPaddingTop());
//     }

//     @Override
//     public boolean onTouchEvent(MotionEvent event) {
//         if (event.getActionMasked() == MotionEvent.ACTION_UP) {
//             // Hack to prevent keyboard and insertion handle from showing.
//             cancelLongPress();
//         }
//         return super.onTouchEvent(event);
//     }

//     @Override
//     protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {
//         super.onMeasure(widthMeasureSpec, heightMeasureSpec);

//         mWidthConstraint =
//                 MeasureSpec.getSize(widthMeasureSpec) - getPaddingLeft() - getPaddingRight();
//         setTextSize(TypedValue.COMPLEX_UNIT_PX, getVariableTextSize(getText().toString()));
//     }

//     @Override
//     public Parcelable onSaveInstanceState() {
//         super.onSaveInstanceState();

//         // EditText will freeze any text with a selection regardless of getFreezesText() ->
//         // return null to prevent any state from being preserved at the instance level.
//         return null;
//     }

//     @Override
//     protected void onTextChanged(CharSequence text, int start, int lengthBefore, int lengthAfter) {
//         super.onTextChanged(text, start, lengthBefore, lengthAfter);

//         final int textLength = text.length();
//         if (getSelectionStart() != textLength || getSelectionEnd() != textLength) {
//             // Pin the selection to the end of the current text.
//             setSelection(textLength);
//         }
//         setTextSize(TypedValue.COMPLEX_UNIT_PX, getVariableTextSize(text.toString()));
//     }

//     @Override
//     public void setTextSize(int unit, float size) {
//         final float oldTextSize = getTextSize();
//         super.setTextSize(unit, size);

//         if (mOnTextSizeChangeListener != null && getTextSize() != oldTextSize) {
//             mOnTextSizeChangeListener.onTextSizeChanged(this, oldTextSize);
//         }
//     }

//     public void setOnTextSizeChangeListener(OnTextSizeChangeListener listener) {
//         mOnTextSizeChangeListener = listener;
//     }

//     public float getVariableTextSize(String text) {
//         if (mWidthConstraint < 0 || mMaximumTextSize <= mMinimumTextSize) {
//             // Not measured, bail early.
//             return getTextSize();
//         }

//         // Capture current paint state.
//         mTempPaint.set(getPaint());

//         // Step through increasing text sizes until the text would no longer fit.
//         float lastFitTextSize = mMinimumTextSize;
//         while (lastFitTextSize < mMaximumTextSize) {
//             final float nextSize = Math.min(lastFitTextSize + mStepTextSize, mMaximumTextSize);
//             mTempPaint.setTextSize(nextSize);
//             if (mTempPaint.measureText(text) > mWidthConstraint) {
//                 break;
//             } else {
//                 lastFitTextSize = nextSize;
//             }
//         }

//         return lastFitTextSize;
//     }

//     @Override
//     public int getCompoundPaddingTop() {
//         // Measure the top padding from the capital letter height of the text instead of the top,
//         // but don't remove more than the available top padding otherwise clipping may occur.
//         getPaint().getTextBounds("H", 0, 1, mTempRect);

//         final FontMetricsInt fontMetrics = getPaint().getFontMetricsInt();
//         final int paddingOffset = -(fontMetrics.ascent + mTempRect.height());
//         return super.getCompoundPaddingTop() - Math.min(getPaddingTop(), paddingOffset);
//     }

//     @Override
//     public int getCompoundPaddingBottom() {
//         // Measure the bottom padding from the baseline of the text instead of the bottom, but don't
//         // remove more than the available bottom padding otherwise clipping may occur.
//         final FontMetricsInt fontMetrics = getPaint().getFontMetricsInt();
//         return super.getCompoundPaddingBottom() - Math.min(getPaddingBottom(), fontMetrics.descent);
//     }

//     public interface OnTextSizeChangeListener {
//         void onTextSizeChanged(TextView textView, float oldSize);
//     }
// }

//--------.java----end----

//--------.h----begin----

// #ifndef _ELASTOS_DROID_CALCULATOR2_CALCULATOREDITTEXT_H__
// #define _ELASTOS_DROID_CALCULATOR2_CALCULATOREDITTEXT_H__

// #include "_Elastos.Droid.Calculator2.h"
// #include <elastos/droid/widget/EditText.h>
// #include <elastos/core/Object.h>
// #include <elastos/droid/ext/frameworkext.h>

// using Elastos::Droid::Content::IContext;
// using Elastos::Droid::Graphics::IPaint;
// using Elastos::Droid::Graphics::IRect;
// using Elastos::Droid::View::EIID_IActionModeCallback;
// using Elastos::Droid::View::IActionMode;
// using Elastos::Droid::View::IActionModeCallback;
// using Elastos::Droid::View::IMenu;
// using Elastos::Droid::View::IMenuItem;
// using Elastos::Droid::View::IMotionEvent;
// using Elastos::Droid::Widget::EditText;

// namespace Elastos {
// namespace Droid {
// namespace Calculator2 {

// class CalculatorEditText
//     : public EditText
//     , public ICalculatorEditText
// {
// private:
//     class MyActionModeCallback
//         : public Object
//         , public IActionModeCallback
//     {
//     public:
//         MyActionModeCallback();

//         CAR_INTERFACE_DECL()

//         CARAPI OnActionItemClicked(
//             /* [in] */ IActionMode* mode,
//             /* [in] */ IMenuItem* item,
//             /* [out] */ Boolean* result);

//         CARAPI OnCreateActionMode(
//             /* [in] */ IActionMode* mode,
//             /* [in] */ IMenu* menu,
//             /* [out] */ Boolean* result);

//         CARAPI OnDestroyActionMode(
//             /* [in] */ IActionMode* mode);

//         CARAPI OnPrepareActionMode(
//             /* [in] */ IActionMode* mode,
//             /* [in] */ IMenu* menu,
//             /* [out] */ Boolean* result);
//     };

// public:
//     CalculatorEditText();

//     virtual ~CalculatorEditText();

//     CAR_INTERFACE_DECL()

//     CARAPI constructor(
//         /* [in] */ IContext* context);

//     CARAPI constructor(
//         /* [in] */ IContext* context,
//         /* [in] */ IAttributeSet* attrs);

//     CARAPI constructor(
//         /* [in] */ IContext* context,
//         /* [in] */ IAttributeSet* attrs,
//         /* [in] */ Int32 defStyle);

//     CARAPI OnTouchEvent(
//         /* [in] */ IMotionEvent* event,
//         /* [out] */ Boolean* result);

//     CARAPI OnSaveInstanceState(
//         /* [out] */ IParcelable* result);

//     CARAPI SetTextSize(
//         /* [in] */ Int32 unit,
//         /* [in] */ Float size);

//     CARAPI SetOnTextSizeChangeListener(
//         /* [in] */ IOnTextSizeChangeListener* listener);

//     CARAPI GetVariableTextSize(
//         /* [in] */ const String& text,
//         /* [out] */ Float* result);

//     CARAPI GetCompoundPaddingTop(
//         /* [out] */ Int32* result);

//     CARAPI GetCompoundPaddingBottom(
//         /* [out] */ Int32* result);

// protected:
//     CARAPI OnMeasure(
//         /* [in] */ Int32 widthMeasureSpec,
//         /* [in] */ Int32 heightMeasureSpec);

//     CARAPI OnTextChanged(
//         /* [in] */ ICharSequence* text,
//         /* [in] */ Int32 start,
//         /* [in] */ Int32 lengthBefore,
//         /* [in] */ Int32 lengthAfter);

// private:
//     static CARAPI_(AutoPtr<MyActionModeCallback>) InitCallback();

// private:
//     static const AutoPtr<MyActionModeCallback> NO_SELECTION_ACTION_MODE_CALLBACK;
//     Float mMaximumTextSize;
//     Float mMinimumTextSize;
//     Float mStepTextSize;

//     // Temporary objects for use in layout methods.
//     AutoPtr<IPaint> mTempPaint;
//     AutoPtr<IRect> mTempRect;

//     Int32 mWidthConstraint;
//     AutoPtr<IOnTextSizeChangeListener> mOnTextSizeChangeListener;
// };

// } // namespace Calculator2
// } // namespace Droid
// } // namespace Elastos

// #endif // _ELASTOS_DROID_CALCULATOR2_CALCULATOREDITTEXT_H__

//--------.h----end----

//--------.cpp----begin----

// #include "elastos/droid/calculator2/CalculatorEditText.h"
// #include "R.h"
// #include <Elastos.Droid.Content.h>
// #include <Elastos.Droid.Graphics.h>
// #include <Elastos.Droid.View.h>
// #include <Elastos.Droid.Text.h>
// #include <elastos/core/Math.h>

// using Elastos::Droid::Content::Res::ITypedArray;
// using Elastos::Droid::Graphics::IPaint;
// using Elastos::Droid::Graphics::IPaintFontMetricsInt;
// using Elastos::Droid::Graphics::CRect;
// using Elastos::Droid::Text::CTextPaint;
// using Elastos::Droid::Text::Method::CScrollingMovementMethodHelper;
// using Elastos::Droid::Text::Method::IScrollingMovementMethodHelper;
// using Elastos::Droid::Utility::ITypedValue;
// using Elastos::Droid::View::IMotionEvent;
// using Elastos::Core::Math;

// namespace Elastos {
// namespace Droid {
// namespace Calculator2 {
// //----------------------------------------------------------------
// //           CalculatorEditText::MyActionModeCallback
// //----------------------------------------------------------------
// CalculatorEditText::MyActionModeCallback::MyActionModeCallback()
// {}

// CAR_INTERFACE_IMPL(CalculatorEditText::MyActionModeCallback, Object, IActionModeCallback)

// ECode CalculatorEditText::MyActionModeCallback::OnActionItemClicked(
//     /* [in] */ IActionMode* mode,
//     /* [in] */ IMenuItem* item,
//     /* [out] */ Boolean* result)
// {
//     VALIDATE_NOT_NULL(result);
//     *result = FALSE;
//     return NOERROR;
// }

// ECode CalculatorEditText::MyActionModeCallback::OnCreateActionMode(
//     /* [in] */ IActionMode* mode,
//     /* [in] */ IMenu* menu,
//     /* [out] */ Boolean* result)
// {
//     VALIDATE_NOT_NULL(result);
//     *result = FALSE;
//     return NOERROR;
// }

// ECode CalculatorEditText::MyActionModeCallback::OnDestroyActionMode(
//     /* [in] */ IActionMode* mode)
// {
//     return NOERROR;
// }

// ECode CalculatorEditText::MyActionModeCallback::OnPrepareActionMode(
//     /* [in] */ IActionMode* mode,
//     /* [in] */ IMenu* menu,
//     /* [out] */ Boolean* result)
// {
//     VALIDATE_NOT_NULL(result);
//     *result = FALSE;
//     return NOERROR;
// }

// //----------------------------------------------------------------
// //           CalculatorEditText
// //----------------------------------------------------------------

// AutoPtr<CalculatorEditText::MyActionModeCallback> CalculatorEditText::InitCallback()
// {
//     return new MyActionModeCallback();
// }
// const AutoPtr<CalculatorEditText::MyActionModeCallback> CalculatorEditText::NO_SELECTION_ACTION_MODE_CALLBACK = InitCallback();

// CalculatorEditText::CalculatorEditText()
//     : mWidthConstraint(-1)
// {
//     CTextPaint::New((IPaint**)&mTempPaint);
//     CRect::New((IRect**)&mTempRect);
// }

// CalculatorEditText::~CalculatorEditText()
// {}

// CAR_INTERFACE_IMPL(CalculatorEditText, EditText, ICalculatorEditText)

// ECode CalculatorEditText::constructor(
//     /* [in] */ IContext* context)
// {
//     return constructor(context, NULL);
// }

// ECode CalculatorEditText::constructor(
//     /* [in] */ IContext* context,
//     /* [in] */ IAttributeSet* attrs)
// {
//     return constructor(context, attrs, 0);
// }

// ECode CalculatorEditText::constructor(
//     /* [in] */ IContext* context,
//     /* [in] */ IAttributeSet* attrs,
//     /* [in] */ Int32 defStyle)
// {
//     EditText::constructor(context, attrs, defStyle);

//     AutoPtr<IAttributeSet> attbs = attrs;
//     AutoPtr<ArrayOf<Int32> > attrIds = ArrayOf<Int32>::Alloc(
//         const_cast<Int32 *>(R::styleable::CalculatorEditText),
//         ArraySize(R::styleable::CalculatorEditText));

//     AutoPtr<ITypedArray> a;
//     context->ObtainStyledAttributes(attbs.Get(), attrIds.Get(), defStyle, 0, (ITypedArray**)&a);

//     Float textsize;
//     GetTextSize(&textsize);
//     a->GetDimension(
//             R::styleable::CalculatorEditText_maxTextSize, textsize, &mMaximumTextSize);
//     a->GetDimension(
//             R::styleable::CalculatorEditText_minTextSize, textsize, &mMinimumTextSize);
//     a->GetDimension(R::styleable::CalculatorEditText_stepTextSize,
//             (mMaximumTextSize - mMinimumTextSize) / 3, &mStepTextSize);

//     a->Recycle();

//     SetCustomSelectionActionModeCallback(
//         IActionModeCallback::Probe(NO_SELECTION_ACTION_MODE_CALLBACK));
//     Boolean flag = FALSE;
//     IsFocusable(&flag);
//     if (flag) {
//         AutoPtr<IScrollingMovementMethodHelper> smm;
//         CScrollingMovementMethodHelper::AcquireSingleton((IScrollingMovementMethodHelper**)&smm);
//         AutoPtr<IMovementMethod> mmd;
//         smm->GetInstance((IMovementMethod**)&mmd);
//         SetMovementMethod(mmd.Get());
//     }
//     SetTextSize(ITypedValue::COMPLEX_UNIT_PX, mMaximumTextSize);
//     Int32 cpaddingBottom;
//     GetCompoundPaddingBottom(&cpaddingBottom);
//     Int32 cpaddingTop;
//     GetCompoundPaddingTop(&cpaddingTop);
//     Int32 lineHeight;
//     GetLineHeight(&lineHeight);

//     return SetMinHeight(lineHeight + cpaddingBottom + cpaddingTop);
// }

// ECode CalculatorEditText::OnTouchEvent(
//     /* [in] */ IMotionEvent* event,
//     /* [out] */ Boolean* result)
// {
//     VALIDATE_NOT_NULL(result);

//     Int32 actionMasked;
//     event->GetActionMasked(&actionMasked);
//     if (actionMasked == IMotionEvent::ACTION_UP) {
//         // Hack to prevent keyboard and insertion handle from showing.
//         CancelLongPress();
//     }

//     return EditText::OnTouchEvent(event, result);
// }

// ECode CalculatorEditText::OnMeasure(
//     /* [in] */ Int32 widthMeasureSpec,
//     /* [in] */ Int32 heightMeasureSpec)
// {
//     EditText::OnMeasure(widthMeasureSpec, heightMeasureSpec);

//     Int32 paddingLeft;
//     GetPaddingLeft(&paddingLeft);
//     Int32 paddingRight;
//     GetPaddingRight(&paddingRight);
//     mWidthConstraint =
//             View::MeasureSpec::GetSize(widthMeasureSpec) - paddingLeft - paddingRight;
//     AutoPtr<ICharSequence> cs;
//     GetText((ICharSequence**)&cs);
//     String str;
//     cs->ToString(&str);
//     Float vol;
//     GetVariableTextSize(str, &vol);
//     SetTextSize(ITypedValue::COMPLEX_UNIT_PX, vol);
//     return NOERROR;
// }

// ECode CalculatorEditText::OnSaveInstanceState(
//     /* [out] */ IParcelable* result)
// {
//     VALIDATE_NOT_NULL(result);
//     AutoPtr<IParcelable> pl = EditText::OnSaveInstanceState();

//     // EditText will freeze any text with a selection regardless of getFreezesText() ->
//     // return null to prevent any state from being preserved at the instance level.
//     result = NULL;
//     return NOERROR;
// }

// ECode CalculatorEditText::OnTextChanged(
//     /* [in] */ ICharSequence* text,
//     /* [in] */ Int32 start,
//     /* [in] */ Int32 lengthBefore,
//     /* [in] */ Int32 lengthAfter)
// {
//     EditText::OnTextChanged(text, start, lengthBefore, lengthAfter);

//     Int32 textLength;
//     text->GetLength(&textLength);
//     Int32 istart;
//     GetSelectionStart(&istart);
//     Int32 end;
//     GetSelectionEnd(&end);
//     if (istart != textLength || end != textLength) {
//         // Pin the selection to the end of the current text.
//         SetSelection(textLength);
//     }
//     String str;
//     text->ToString(&str);
//     Float vol;
//     GetVariableTextSize(str, &vol);
//     return SetTextSize(ITypedValue::COMPLEX_UNIT_PX, vol);
// }

// ECode CalculatorEditText::SetTextSize(
//     /* [in] */ Int32 unit,
//     /* [in] */ Float size)
// {
//     Float oldTextSize;
//     GetTextSize(&oldTextSize);
//     EditText::SetTextSize(unit, size);

//     Float fvol;
//     if (mOnTextSizeChangeListener != NULL && (GetTextSize(&fvol), fvol != oldTextSize)) {
//         mOnTextSizeChangeListener->OnTextSizeChanged(this, oldTextSize);
//     }
//     return NOERROR;
// }

// ECode CalculatorEditText::SetOnTextSizeChangeListener(
//     /* [in] */ IOnTextSizeChangeListener* listener)
// {
//     mOnTextSizeChangeListener = listener;
//     return NOERROR;
// }

// ECode CalculatorEditText::GetVariableTextSize(
//     /* [in] */ const String& text,
//     /* [out] */ Float* result)
// {
//     VALIDATE_NOT_NULL(result);

//     if (mWidthConstraint < 0 || mMaximumTextSize <= mMinimumTextSize) {
//         // Not measured, bail early.
//         Float size;
//         GetTextSize(&size);
//         *result = size;
//         return NOERROR;
//     }

//     // Capture current paint state.
//     AutoPtr<ITextPaint> paint;
//     GetPaint((ITextPaint**)&paint);
//     mTempPaint->Set(IPaint::Probe(paint));

//     // Step through increasing text sizes until the text would no longer fit.
//     Float lastFitTextSize = mMinimumTextSize;
//     Float width;
//     while (lastFitTextSize < mMaximumTextSize) {
//         Float nextSize = Elastos::Core::Math::Min(lastFitTextSize + mStepTextSize, mMaximumTextSize);
//         mTempPaint->SetTextSize(nextSize);

//         mTempPaint->MeasureText(text, &width);
//         if (width > mWidthConstraint) {
//             break;
//         }
//         else {
//             lastFitTextSize = nextSize;
//         }
//     }

//     *result = lastFitTextSize;
//     return NOERROR;
// }

// ECode CalculatorEditText::GetCompoundPaddingTop(
//     /* [out] */ Int32* result)
// {
//     VALIDATE_NOT_NULL(result);

//     // Measure the top padding from the capital letter height of the text instead of the top,
//     // but don't remove more than the available top padding otherwise clipping may occur.
//     AutoPtr<ITextPaint> tp;
//     GetPaint((ITextPaint**)&tp);
//     IPaint::Probe(tp)->GetTextBounds(String("H"), 0, 1, mTempRect);
//     AutoPtr<IPaintFontMetricsInt> fontMetrics;
//     IPaint::Probe(tp)->GetFontMetricsInt((IPaintFontMetricsInt**)&fontMetrics);
//     Int32 height;
//     mTempRect->GetHeight(&height);
//     Int32 ascent;
//     fontMetrics->GetAscent(&ascent);
//     Int32 paddingOffset = -(ascent + height);
//     Int32 top;
//     EditText::GetCompoundPaddingTop(&top);
//     Int32 paddingTop;
//     GetPaddingTop(&paddingTop);
//     *result = top - Elastos::Core::Math::Min(paddingTop, paddingOffset);
//     return NOERROR;
// }

// ECode CalculatorEditText::GetCompoundPaddingBottom(
//     /* [out] */ Int32* result)
// {
//     VALIDATE_NOT_NULL(result);

//     // Measure the bottom padding from the baseline of the text instead of the bottom, but don't
//     // remove more than the available bottom padding otherwise clipping may occur.
//     AutoPtr<ITextPaint> tp;
//     GetPaint((ITextPaint**)&tp);
//     AutoPtr<IPaintFontMetricsInt> fontMetrics;
//     IPaint::Probe(tp)->GetFontMetricsInt((IPaintFontMetricsInt**)&fontMetrics);
//     Int32 bottom;
//     GetPaddingBottom(&bottom);
//     Int32 descent;
//     fontMetrics->GetDescent(&descent);
//     Int32 vbottom;
//     EditText::GetCompoundPaddingBottom(&vbottom);
//     *result = vbottom - Elastos::Core::Math::Min(bottom, descent);
//     return NOERROR;
// }

// } // namespace Calculator2
// } // namespace Droid
// } // namespace Elastos

//--------.cpp----end----

//--------Listener----default begin----

    // _apt.OnCreate = function(context, savedInstanceState){
    //     elog('====jso_activity_cb====OnCreate.begin====');
    // }  //OnCreate
    _apt.OnStart = function(context){
        elog('====jso_activity_cb====OnStart.begin====');
    }
    _apt.OnResume = function(context){
        elog('====jso_activity_cb====OnResume.begin====');
    }
    _apt.OnPause = function(context){
        elog('====jso_activity_cb====OnPause.begin====');
    }
    _apt.OnStop = function(context){
        elog('====jso_activity_cb====OnStop.begin====');
    }
    _apt.OnDestroy = function(context){
        elog('====jso_activity_cb====OnDestroy.begin====');
    }
    _apt.OnActivityResult = function(context, aiRequestCode, aiResultCode, aoIntentData){
        elog('====jso_activity_cb====OnActivityResult.begin====');
    }
    _apt.OnCreateDialog = function(context, aiId, out_aoDialog){
        elog('====jso_activity_cb====OnCreateDialog.begin====');
    }   //OnCreateDialog
    _apt.OnCreateContextMenu = function(context, aoMenu, aoV, aoMenuInfo){
        elog('====jso_activity_cb====OnCreateContextMenu.begin====');
    }
    _apt.CreateNavigationBar = function(context){
        elog('====jso_activity_cb====CreateNavigationBar.begin====');
    }
    _apt.OnExchangeData = function(aiTimes ,aoInObject, aoOutObject) {
        elog('====jso_activity_cb====OnExchangeData.begin====');
    }
    _apt.OnHandleMessage = function(context, aoMessage){
        elog('====jso_activity_cb====OnHandleMessage.begin====');
    }

//--------Listener----default end----

    return new CActivityListener(oActivity);
};  //module.exports