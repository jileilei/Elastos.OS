#ifndef __ELASTOS_DROID_TEXT_STYLE_MetricAffectingSpan_H__
#define __ELASTOS_DROID_TEXT_STYLE_MetricAffectingSpan_H__

#include "Elastos.Droid.Text.h"
#include "elastos/droid/text/style/CharacterStyle.h"

using Elastos::Droid::Text::Style::IMetricAffectingSpan;

namespace Elastos {
namespace Droid {
namespace Text {
namespace Style {

/**
 * The classes that affect character-level text formatting in a way that
 * changes the width or height of characters extend this class.
 */
class MetricAffectingSpan
    : public CharacterStyle
    , public IMetricAffectingSpan
    , public IUpdateLayout
    , public IUpdateAppearance
{
public:
    CAR_INTERFACE_DECL()

    MetricAffectingSpan();

    virtual ~MetricAffectingSpan();

    virtual CARAPI UpdateMeasureState(
        /* [in] */ ITextPaint* p) = 0;

    /**
     * Returns "this" for most MetricAffectingSpans, but for
     * MetricAffectingSpans that were generated by {@link #wrap},
     * returns the underlying MetricAffectingSpan.
     */
    //@Override
    CARAPI GetUnderlying(
        /* [out] */ ICharacterStyle** style);
};

/**
 * A Passthrough MetricAffectingSpan is one that
 * passes {@link #updateDrawState} and {@link #updateMeasureState}
 * calls through to the specified MetricAffectingSpan
 * while still being a distinct object,
 * and is therefore able to be attached to the same Spannable
 * to which the specified MetricAffectingSpan is already attached.
 */
/* package */
//static
class MetricAffectingSpanPassthrough
    : public MetricAffectingSpan
{
public:
    /**
     * Creates a new Passthrough of the specfied MetricAffectingSpan.
     */
    MetricAffectingSpanPassthrough(
        /* [in] */ IMetricAffectingSpan* cs);

    /**
     * Passes updateDrawState through to the underlying MetricAffectingSpan.
     */
    //@Override
    CARAPI UpdateDrawState(
        /* [in] */ ITextPaint* tp);

    /**
     * Passes updateMeasureState through to the underlying MetricAffectingSpan.
     */
    //@Override
    CARAPI UpdateMeasureState(
        /* [in] */ ITextPaint* tp);

    /**
     * Returns the MetricAffectingSpan underlying this one, or the one
     * underlying it if it too is a Passthrough.
     */
    //@Override
    CARAPI GetUnderlying(
        /* [out] */ ICharacterStyle** result);

private:
    AutoPtr<IMetricAffectingSpan> mStyle;
};

} // namespace Style
} // namespace Text
} // namepsace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_TEXT_STYLE_MetricAffectingSpan_H__