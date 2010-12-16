using System;
using System.Runtime.InteropServices;
using System.Text;
using System.Collections.Generic;

namespace Zapp.Core
{
    /// <summary>
    /// Description of the type plus any bounds of action arguments plus properties.  Only intended for use by auto-generated proxies and providers.
    /// </summary>
    /// <remarks>Each action owns 0..n parameters;  each property owns exactly 1.</remarks>
    public class Parameter
    {
        protected IntPtr iHandle;

        public IntPtr Handle()
        {
            return iHandle;
        }
        
        protected Parameter()
        {
        }
    }
    
    /// <summary>
    /// Integer type parameter.  Only intended for use by auto-generated proxies and providers.
    /// </summary>
    public class ParameterInt : Parameter
    {
        [DllImport("ZappUpnp")]
        static extern unsafe IntPtr ServiceParameterCreateInt(char* aName, int aMinValue, int aMaxValue, int aStep);

        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="aName">Parameter name</param>
        /// <param name="aMinValue">Minimum allowed value</param>
        /// <param name="aMaxValue">Maximum allowed value</param>
        /// <param name="aStep">Gap between allowed values</param>
        public unsafe ParameterInt(String aName, int aMinValue = Int32.MinValue, int aMaxValue = Int32.MaxValue, int aStep = 1)
        {
            char* name = (char*)Marshal.StringToHGlobalAnsi(aName);
            iHandle = ServiceParameterCreateInt(name, aMinValue, aMaxValue, aStep);
            Marshal.FreeHGlobal((IntPtr)name);
        }
    }

    /// <summary>
    /// Unsigned integer type parameter.  Only intended for use by auto-generated proxies and providers.
    /// </summary>
    public class ParameterUint : Parameter
    {
        [DllImport("ZappUpnp")]
        static extern unsafe IntPtr ServiceParameterCreateUint(char* aName, uint aMinValue, uint aMaxValue, uint aStep);

        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="aName">Parameter name</param>
        /// <param name="aMinValue">Minimum allowed value</param>
        /// <param name="aMaxValue">Maximum allowed value</param>
        /// <param name="aStep">Gap between allowed values</param>
        public unsafe ParameterUint(String aName, uint aMinValue = 0, uint aMaxValue = uint.MaxValue, uint aStep = 1)
        {
            char* name = (char*)Marshal.StringToHGlobalAnsi(aName);
            iHandle = ServiceParameterCreateUint(name, aMinValue, aMaxValue, aStep);
            Marshal.FreeHGlobal((IntPtr)name);
        }
    }

    /// <summary>
    /// Boolean type parameter.  Only intended for use by auto-generated proxies and providers.
    /// </summary>
    public class ParameterBool : Parameter
    {
        [DllImport("ZappUpnp")]
        static extern unsafe IntPtr ServiceParameterCreateBool(char* aName);

        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="aName">Parameter name</param>
        public unsafe ParameterBool(String aName)
        {
            char* name = (char*)Marshal.StringToHGlobalAnsi(aName);
            iHandle = ServiceParameterCreateBool(name);
            Marshal.FreeHGlobal((IntPtr)name);
        }
    }

    /// <summary>
    /// String type parameter.  Only intended for use by auto-generated proxies and providers.
    /// </summary>
    public class ParameterString : Parameter
    {
        [DllImport("ZappUpnp")]
        static extern unsafe IntPtr ServiceParameterCreateString(char* aName, char** aAllowedValues, uint aCount);

        /// <summary>
        /// 
        /// </summary>
        /// <param name="aName">Parameter name</param>
        /// <param name="aAllowedValues">List of allowed values for the string</param>
        public unsafe ParameterString(String aName, List<String> aAllowedValues)
        {
            // !!!! assumes sizeof(IntPtr) == 4
            char* name = (char*)Marshal.StringToHGlobalAnsi(aName);
            char** allowed = (char**)Marshal.AllocHGlobal(4 * aAllowedValues.Count);
            for (int i = 0; i < aAllowedValues.Count; i++)
            {
                char* val = (char*)Marshal.StringToHGlobalAnsi(aAllowedValues[i]);
                allowed[i] = val;
            }
            iHandle = ServiceParameterCreateString(name, allowed, (uint)aAllowedValues.Count);
            for (uint i = 0; i < aAllowedValues.Count; i++)
            {
                Marshal.FreeHGlobal((IntPtr)allowed[i]);
            }
            Marshal.FreeHGlobal((IntPtr)allowed);
            Marshal.FreeHGlobal((IntPtr)name);
        }
    }

    /// <summary>
    /// String type parameter.  Only intended for use by auto-generated proxies and providers.
    /// </summary>
    public class ParameterBinary : Parameter
    {
        [DllImport("ZappUpnp")]
        static extern unsafe IntPtr ServiceParameterCreateBinary(char* aName);

        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="aName">Parameter name</param>
        public unsafe ParameterBinary(String aName)
        {
            char* name = (char*)Marshal.StringToHGlobalAnsi(aName);
            iHandle = ServiceParameterCreateBinary(name);
            Marshal.FreeHGlobal((IntPtr)name);
        }
    }

    public class ParameterRelated : Parameter
    {
        [DllImport("ZappUpnp")]
        static extern unsafe IntPtr ServiceParameterCreateRelated(char* aName, IntPtr aProperty);

        public unsafe ParameterRelated(String aName, Zapp.Core.Property aProperty)
        {
            char* name = (char*)Marshal.StringToHGlobalAnsi(aName);
            iHandle = ServiceParameterCreateRelated(name, aProperty.Handle());
            Marshal.FreeHGlobal((IntPtr)name);
        }
    }

    /// <summary>
    /// (Service) Property.  Only intended for use by auto-generated proxies and providers.
    /// </summary>
    /// <remarks>One Property will be created per Property (state variable) for the Service</remarks>
    public class Property : IDisposable
    {
        public delegate void CallbackValueChanged();
        protected delegate void Callback(IntPtr aPtr);

        protected IntPtr iHandle;
        protected GCHandle iGch;
        protected Callback iCallbackValueChanged;
        private CallbackValueChanged iValueChanged;

        public void Dispose()
        {
            iGch.Free();
        }

        internal IntPtr Handle()
        {
            return iHandle;
        }
        
        protected Property()
        {
            iGch = GCHandle.Alloc(this);
        }

        protected Property(CallbackValueChanged aValueChanged)
        {
            iGch = GCHandle.Alloc(this);
            iValueChanged = aValueChanged;
            iCallbackValueChanged = new Callback(ValueChanged);
        }

        private void ValueChanged(IntPtr aPtr)
        {
            GCHandle gch = GCHandle.FromIntPtr(aPtr);
            Property self = (Property)gch.Target;
            self.iValueChanged();
        }
    }

    /// <summary>
    /// Integer type property.  Only intended for use by auto-generated proxies and providers.
    /// </summary>
    public class PropertyInt : Property
    {
        [DllImport("ZappUpnp")]
        static extern unsafe IntPtr ServicePropertyCreateIntCp(char* aName, Callback aCallback, IntPtr aPtr);
        [DllImport("ZappUpnp")]
        static extern IntPtr ServicePropertyCreateIntDv(IntPtr aParameterHandle);
        [DllImport("ZappUpnp")]
        static extern int ServicePropertyValueInt(IntPtr aHandle);

        /// <summary>
        /// Constructor suitable for use by clients of the control point stack
        /// </summary>
        /// <param name="aName">Property name</param>
        /// <param name="aValueChanged">Delegate to run when the property's value changes</param>
        public unsafe PropertyInt(String aName, CallbackValueChanged aValueChanged)
            : base(aValueChanged)
        {
            IntPtr ptr = GCHandle.ToIntPtr(iGch);
            char* name = (char*)Marshal.StringToHGlobalAnsi(aName);
            iHandle = ServicePropertyCreateIntCp(name, iCallbackValueChanged, ptr);
            Marshal.FreeHGlobal((IntPtr)name);
        }

        /// <summary>
        /// Constructor suitable for use by clients of the device stack
        /// </summary>
        /// <param name="aParameter">Parameter defining the name and any value bounds for the property</param>
        public PropertyInt(ParameterInt aParameter)
        {
            iHandle = ServicePropertyCreateIntDv(aParameter.Handle());
        }

        /// <summary>
        /// Query the value of the property
        /// </summary>
        /// <returns>Integer property value</returns>
        public int Value()
        {
            return ServicePropertyValueInt(iHandle);
        }
    }

    /// <summary>
    /// Unsigned integer type property.  Only intended for use by auto-generated proxies and providers.
    /// </summary>
    public class PropertyUint : Property
    {
        [DllImport("ZappUpnp")]
        static extern unsafe IntPtr ServicePropertyCreateUintCp(char* aName, Callback aCallback, IntPtr aPtr);
        [DllImport("ZappUpnp")]
        static extern IntPtr ServicePropertyCreateUintDv(IntPtr aParameterHandle);
        [DllImport("ZappUpnp")]
        static extern uint ServicePropertyValueUint(IntPtr aHandle);

        /// <summary>
        /// Constructor suitable for use by clients of the control point stack
        /// </summary>
        /// <param name="aName">Property name</param>
        /// <param name="aValueChanged">Delegate to run when the property's value changes</param>
        public unsafe PropertyUint(String aName, CallbackValueChanged aValueChanged)
            : base(aValueChanged)
        {
            IntPtr ptr = GCHandle.ToIntPtr(iGch);
            char* name = (char*)Marshal.StringToHGlobalAnsi(aName);
            iHandle = ServicePropertyCreateUintCp(name, iCallbackValueChanged, ptr);
            Marshal.FreeHGlobal((IntPtr)name);
        }

        /// <summary>
        /// Constructor suitable for use by clients of the device stack
        /// </summary>
        /// <param name="aParameter">Parameter defining the name and any value bounds for the property</param>
        public PropertyUint(ParameterUint aParameter)
        {
            iHandle = ServicePropertyCreateUintDv(aParameter.Handle());
        }

        /// <summary>
        /// Query the value of the property
        /// </summary>
        /// <returns>Unsigned integer property value</returns>
        public uint Value()
        {
            return ServicePropertyValueUint(iHandle);
        }
    }

    /// <summary>
    /// Boolean type property.  Only intended for use by auto-generated proxies and providers.
    /// </summary>
    public class PropertyBool : Property
    {
        [DllImport("ZappUpnp")]
        static extern unsafe IntPtr ServicePropertyCreateBoolCp(char* aName, Callback aCallback, IntPtr aPtr);
        [DllImport("ZappUpnp")]
        static extern IntPtr ServicePropertyCreateBoolDv(IntPtr aParameterHandle);
        [DllImport("ZappUpnp")]
        static extern uint ServicePropertyValueBool(IntPtr aHandle);

        /// <summary>
        /// Constructor suitable for use by clients of the control point stack
        /// </summary>
        /// <param name="aName">Property name</param>
        /// <param name="aValueChanged">Delegate to run when the property's value changes</param>
        public unsafe PropertyBool(String aName, CallbackValueChanged aValueChanged)
            : base(aValueChanged)
        {
            IntPtr ptr = GCHandle.ToIntPtr(iGch);
            char* name = (char*)Marshal.StringToHGlobalAnsi(aName);
            iHandle = ServicePropertyCreateBoolCp(name, iCallbackValueChanged, ptr);
            Marshal.FreeHGlobal((IntPtr)name);
        }

        /// <summary>
        /// Constructor suitable for use by clients of the device stack
        /// </summary>
        /// <param name="aParameter">Parameter defining the name for the property</param>
        public PropertyBool(ParameterBool aParameter)
        {
            iHandle = ServicePropertyCreateBoolDv(aParameter.Handle());
        }

        /// <summary>
        /// Query the value of the property
        /// </summary>
        /// <returns>Boolean property value</returns>
        public bool Value()
        {
            uint val = ServicePropertyValueBool(iHandle);
            return (val != 0);
        }
    }

    /// <summary>
    /// String type property.  Only intended for use by auto-generated proxies and providers.
    /// </summary>
    public class PropertyString : Property
    {
        [DllImport("ZappUpnp")]
        static extern unsafe IntPtr ServicePropertyCreateStringCp(char* aName, Callback aCallback, IntPtr aPtr);
        [DllImport("ZappUpnp")]
        static extern IntPtr ServicePropertyCreateStringDv(IntPtr aParameterHandle);
        [DllImport("ZappUpnp")]
        static extern unsafe char* ServicePropertyValueString(IntPtr aHandle);
        [DllImport("ZappUpnp")]
        static extern unsafe void ZappFree(IntPtr aPtr);

        /// <summary>
        /// Constructor suitable for use by clients of the control point stack
        /// </summary>
        /// <param name="aName">Property name</param>
        /// <param name="aValueChanged">Delegate to run when the property's value changes</param>
        public unsafe PropertyString(String aName, CallbackValueChanged aValueChanged)
            : base(aValueChanged)
        {
            IntPtr ptr = GCHandle.ToIntPtr(iGch);
            char* name = (char*)Marshal.StringToHGlobalAnsi(aName);
            iHandle = ServicePropertyCreateStringCp(name, iCallbackValueChanged, ptr);
            Marshal.FreeHGlobal((IntPtr)name);
        }

        /// <summary>
        /// Constructor suitable for use by clients of the device stack
        /// </summary>
        /// <param name="aParameter">Parameter defining the name and any set of allowed values for the property</param>
        public PropertyString(ParameterString aParameter)
        {
            iHandle = ServicePropertyCreateStringDv(aParameter.Handle());
        }

        /// <summary>
        /// Query the value of the property
        /// </summary>
        /// <returns>String property value</returns>
        public unsafe String Value()
        {
            char* cStr = ServicePropertyValueString(iHandle);
            String str = Marshal.PtrToStringAnsi((IntPtr)cStr);
            ZappFree((IntPtr)cStr);
            return str;
        }
    }

    /// <summary>
    /// Binary type property.  Only intended for use by auto-generated proxies and providers.
    /// </summary>
    public class PropertyBinary : Property
    {
        [DllImport("ZappUpnp")]
        static extern unsafe IntPtr ServicePropertyCreateBinaryCp(char* aName, Callback aCallback, IntPtr aPtr);
        [DllImport("ZappUpnp")]
        static extern IntPtr ServicePropertyCreateBinaryDv(IntPtr aParameterHandle);
        [DllImport("ZappUpnp")]
        static extern unsafe char* ServicePropertyGetValueBinary(IntPtr aHandle, char** aData, uint* aLen);
        [DllImport("ZappUpnp")]
        static extern unsafe void ZappFree(IntPtr aPtr);

        /// <summary>
        /// Constructor suitable for use by clients of the control point stack
        /// </summary>
        /// <param name="aName">Property name</param>
        /// <param name="aValueChanged">Delegate to run when the property's value changes</param>
        public unsafe PropertyBinary(String aName, CallbackValueChanged aValueChanged)
            : base(aValueChanged)
        {
            IntPtr ptr = GCHandle.ToIntPtr(iGch);
            char* name = (char*)Marshal.StringToHGlobalAnsi(aName);
            iHandle = ServicePropertyCreateBinaryCp(name, iCallbackValueChanged, ptr);
            Marshal.FreeHGlobal((IntPtr)name);
        }

        /// <summary>
        /// Constructor suitable for use by clients of the device stack
        /// </summary>
        /// <param name="aParameter">Parameter defining the name for the property</param>
        public PropertyBinary(ParameterBinary aParameter)
        {
            iHandle = ServicePropertyCreateBinaryDv(aParameter.Handle());
        }

        /// <summary>
        /// Query the value of the property
        /// </summary>
        /// <returns>Binary property value</returns>
        public unsafe String Value()
        {
            char* data;
            uint len;
            ServicePropertyGetValueBinary(iHandle, &data, &len);
            String bin = Marshal.PtrToStringAnsi((IntPtr)data, (int)len);
            ZappFree((IntPtr)data);
            return bin;
        }
    }

    /// <summary>
    /// (Service) Action
    /// </summary>
    /// <remarks>Each service has 0..n of these.  Each action has 0..n input parameters and
    /// 0..m output parameters.  Each parameter must be either input or output.</remarks>
    public class Action : IDisposable
    {
        [DllImport("ZappUpnp")]
        static extern unsafe IntPtr ServiceActionCreate(char* aName);
        [DllImport("ZappUpnp")]
        static extern void ServiceActionDestroy(IntPtr aAction);
        [DllImport("ZappUpnp")]
        static extern void ServiceActionAddInputParameter(IntPtr aAction, IntPtr aParameter);
        [DllImport("ZappUpnp")]
        static extern void ServiceActionAddOutputParameter(IntPtr aAction, IntPtr aParameter);
        [DllImport("ZappUpnp")]
        static extern unsafe char* ServiceActionName(IntPtr aAction);

        private IntPtr iHandle;
        private List<Parameter> iInputParameters;
        private List<Parameter> iOutputParameters;
        
        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="aName">Action name</param>
        public unsafe Action(String aName)
        {
            char* name = (char*)Marshal.StringToHGlobalAnsi(aName);
            iHandle = ServiceActionCreate(name);
            Marshal.FreeHGlobal((IntPtr)name);
            iInputParameters = new List<Parameter>();
            iOutputParameters = new List<Parameter>();
        }

        /// <summary>
        /// Add an input parameter
        /// </summary>
        /// <param name="aParameter">Input parameter.  Ownership is passed to the action</param>
        public void AddInputParameter(Parameter aParameter)
        {
            iInputParameters.Add(aParameter);
            ServiceActionAddInputParameter(iHandle, aParameter.Handle());
        }

        /// <summary>
        /// Add an output parameter
        /// </summary>
        /// <param name="aParameter">Output parameter.  Ownership is passed to the action</param>
        public void AddOutputParameter(Parameter aParameter)
        {
            iOutputParameters.Add(aParameter);
            ServiceActionAddOutputParameter(iHandle, aParameter.Handle());
        }

        /// <summary>
        /// Retrieve an input parameter
        /// </summary>
        /// <param name="aIndex">(Zero-based) Index of the parameter</param>
        /// <returns>The relevant input parameter</returns>
        public Parameter InputParameter(int aIndex)
        {
            return iInputParameters[aIndex];
        }

        /// <summary>
        /// Retrieve an output parameter
        /// </summary>
        /// <param name="aIndex">(Zero-based) Index of the parameter</param>
        /// <returns>The relevant output parameter</returns>
        public Parameter OutputParameter(int aIndex)
        {
            return iOutputParameters[aIndex];
        }

        /// <summary>
        /// Query the name of the action
        /// </summary>
        /// <returns>Action name</returns>
        public unsafe String Name()
        {
            char* str = ServiceActionName(iHandle);
            return Marshal.PtrToStringAnsi((IntPtr)str);
        }

        internal IntPtr Handle()
        {
            return iHandle;
        }

        public void Dispose()
        {
            lock (this)
            {
                if (iHandle == IntPtr.Zero)
                {
                    return;
                }
                iHandle = IntPtr.Zero;
            }
            ServiceActionDestroy(iHandle);
        }
    }
}