 

/**
* Service Proxy for CpProxyAvOpenhomeOrgMediaServer1
* @module ohNet
* @class MediaServer
*/
	
var CpProxyAvOpenhomeOrgMediaServer1 = function(udn){	

	this.url = window.location.protocol + "//" + window.location.host + "/" + udn + "/av.openhome.org-MediaServer-1/control";  // upnp control url
	this.domain = "av-openhome-org";
	this.type = "MediaServer";
	this.version = "1";
	this.serviceName = "av.openhome.org-MediaServer-1";
	this.subscriptionId = "";  // Subscription identifier unique to each Subscription Manager 
	this.udn = udn;   // device name
	
	// Collection of service properties
	this.serviceProperties = {};
	this.serviceProperties["ManufacturerName"] = new OhNet.ServiceProperty("ManufacturerName","string");
	this.serviceProperties["ManufacturerInfo"] = new OhNet.ServiceProperty("ManufacturerInfo","string");
	this.serviceProperties["ManufacturerUrl"] = new OhNet.ServiceProperty("ManufacturerUrl","string");
	this.serviceProperties["ManufacturerImageUri"] = new OhNet.ServiceProperty("ManufacturerImageUri","string");
	this.serviceProperties["ModelName"] = new OhNet.ServiceProperty("ModelName","string");
	this.serviceProperties["ModelInfo"] = new OhNet.ServiceProperty("ModelInfo","string");
	this.serviceProperties["ModelUrl"] = new OhNet.ServiceProperty("ModelUrl","string");
	this.serviceProperties["ModelImageUri"] = new OhNet.ServiceProperty("ModelImageUri","string");
	this.serviceProperties["ProductName"] = new OhNet.ServiceProperty("ProductName","string");
	this.serviceProperties["ProductInfo"] = new OhNet.ServiceProperty("ProductInfo","string");
	this.serviceProperties["ProductUrl"] = new OhNet.ServiceProperty("ProductUrl","string");
	this.serviceProperties["ProductImageUri"] = new OhNet.ServiceProperty("ProductImageUri","string");
	this.serviceProperties["Attributes"] = new OhNet.ServiceProperty("Attributes","string");
}



/**
* Subscribes the service to the subscription manager to listen for property change events
* @method Subscribe
* @param {Function} serviceAddedFunction The function that executes once the subscription is successful
*/
CpProxyAvOpenhomeOrgMediaServer1.prototype.subscribe = function (serviceAddedFunction) {
    OhNet.SubscriptionManager.addService(this,serviceAddedFunction);
}


/**
* Unsubscribes the service from the subscription manager to stop listening for property change events
* @method Unsubscribe
*/
CpProxyAvOpenhomeOrgMediaServer1.prototype.unsubscribe = function () {
    OhNet.SubscriptionManager.removeService(this.subscriptionId);
}


	

/**
* Adds a listener to handle "ManufacturerName" property change events
* @method ManufacturerName_Changed
* @param {Function} stateChangedFunction The handler for state changes
*/
CpProxyAvOpenhomeOrgMediaServer1.prototype.ManufacturerName_Changed = function (stateChangedFunction) {
    this.serviceProperties.ManufacturerName.addListener(function (state) 
	{ 
		stateChangedFunction(OhNet.SoapRequest.readStringParameter(state)); 
	});
}
	

/**
* Adds a listener to handle "ManufacturerInfo" property change events
* @method ManufacturerInfo_Changed
* @param {Function} stateChangedFunction The handler for state changes
*/
CpProxyAvOpenhomeOrgMediaServer1.prototype.ManufacturerInfo_Changed = function (stateChangedFunction) {
    this.serviceProperties.ManufacturerInfo.addListener(function (state) 
	{ 
		stateChangedFunction(OhNet.SoapRequest.readStringParameter(state)); 
	});
}
	

/**
* Adds a listener to handle "ManufacturerUrl" property change events
* @method ManufacturerUrl_Changed
* @param {Function} stateChangedFunction The handler for state changes
*/
CpProxyAvOpenhomeOrgMediaServer1.prototype.ManufacturerUrl_Changed = function (stateChangedFunction) {
    this.serviceProperties.ManufacturerUrl.addListener(function (state) 
	{ 
		stateChangedFunction(OhNet.SoapRequest.readStringParameter(state)); 
	});
}
	

/**
* Adds a listener to handle "ManufacturerImageUri" property change events
* @method ManufacturerImageUri_Changed
* @param {Function} stateChangedFunction The handler for state changes
*/
CpProxyAvOpenhomeOrgMediaServer1.prototype.ManufacturerImageUri_Changed = function (stateChangedFunction) {
    this.serviceProperties.ManufacturerImageUri.addListener(function (state) 
	{ 
		stateChangedFunction(OhNet.SoapRequest.readStringParameter(state)); 
	});
}
	

/**
* Adds a listener to handle "ModelName" property change events
* @method ModelName_Changed
* @param {Function} stateChangedFunction The handler for state changes
*/
CpProxyAvOpenhomeOrgMediaServer1.prototype.ModelName_Changed = function (stateChangedFunction) {
    this.serviceProperties.ModelName.addListener(function (state) 
	{ 
		stateChangedFunction(OhNet.SoapRequest.readStringParameter(state)); 
	});
}
	

/**
* Adds a listener to handle "ModelInfo" property change events
* @method ModelInfo_Changed
* @param {Function} stateChangedFunction The handler for state changes
*/
CpProxyAvOpenhomeOrgMediaServer1.prototype.ModelInfo_Changed = function (stateChangedFunction) {
    this.serviceProperties.ModelInfo.addListener(function (state) 
	{ 
		stateChangedFunction(OhNet.SoapRequest.readStringParameter(state)); 
	});
}
	

/**
* Adds a listener to handle "ModelUrl" property change events
* @method ModelUrl_Changed
* @param {Function} stateChangedFunction The handler for state changes
*/
CpProxyAvOpenhomeOrgMediaServer1.prototype.ModelUrl_Changed = function (stateChangedFunction) {
    this.serviceProperties.ModelUrl.addListener(function (state) 
	{ 
		stateChangedFunction(OhNet.SoapRequest.readStringParameter(state)); 
	});
}
	

/**
* Adds a listener to handle "ModelImageUri" property change events
* @method ModelImageUri_Changed
* @param {Function} stateChangedFunction The handler for state changes
*/
CpProxyAvOpenhomeOrgMediaServer1.prototype.ModelImageUri_Changed = function (stateChangedFunction) {
    this.serviceProperties.ModelImageUri.addListener(function (state) 
	{ 
		stateChangedFunction(OhNet.SoapRequest.readStringParameter(state)); 
	});
}
	

/**
* Adds a listener to handle "ProductName" property change events
* @method ProductName_Changed
* @param {Function} stateChangedFunction The handler for state changes
*/
CpProxyAvOpenhomeOrgMediaServer1.prototype.ProductName_Changed = function (stateChangedFunction) {
    this.serviceProperties.ProductName.addListener(function (state) 
	{ 
		stateChangedFunction(OhNet.SoapRequest.readStringParameter(state)); 
	});
}
	

/**
* Adds a listener to handle "ProductInfo" property change events
* @method ProductInfo_Changed
* @param {Function} stateChangedFunction The handler for state changes
*/
CpProxyAvOpenhomeOrgMediaServer1.prototype.ProductInfo_Changed = function (stateChangedFunction) {
    this.serviceProperties.ProductInfo.addListener(function (state) 
	{ 
		stateChangedFunction(OhNet.SoapRequest.readStringParameter(state)); 
	});
}
	

/**
* Adds a listener to handle "ProductUrl" property change events
* @method ProductUrl_Changed
* @param {Function} stateChangedFunction The handler for state changes
*/
CpProxyAvOpenhomeOrgMediaServer1.prototype.ProductUrl_Changed = function (stateChangedFunction) {
    this.serviceProperties.ProductUrl.addListener(function (state) 
	{ 
		stateChangedFunction(OhNet.SoapRequest.readStringParameter(state)); 
	});
}
	

/**
* Adds a listener to handle "ProductImageUri" property change events
* @method ProductImageUri_Changed
* @param {Function} stateChangedFunction The handler for state changes
*/
CpProxyAvOpenhomeOrgMediaServer1.prototype.ProductImageUri_Changed = function (stateChangedFunction) {
    this.serviceProperties.ProductImageUri.addListener(function (state) 
	{ 
		stateChangedFunction(OhNet.SoapRequest.readStringParameter(state)); 
	});
}
	

/**
* Adds a listener to handle "Attributes" property change events
* @method Attributes_Changed
* @param {Function} stateChangedFunction The handler for state changes
*/
CpProxyAvOpenhomeOrgMediaServer1.prototype.Attributes_Changed = function (stateChangedFunction) {
    this.serviceProperties.Attributes.addListener(function (state) 
	{ 
		stateChangedFunction(OhNet.SoapRequest.readStringParameter(state)); 
	});
}


/**
* A service action to Manufacturer
* @method Manufacturer
* @param {Function} successFunction The function that is executed when the action has completed successfully
* @param {Function} errorFunction The function that is executed when the action has cause an error
*/
CpProxyAvOpenhomeOrgMediaServer1.prototype.Manufacturer = function(successFunction, errorFunction){	
	var request = new OhNet.SoapRequest("Manufacturer", this.url, this.domain, this.type, this.version);		
    request.send(function(result){
		result["Name"] = OhNet.SoapRequest.readStringParameter(result["Name"]);	
		result["Info"] = OhNet.SoapRequest.readStringParameter(result["Info"]);	
		result["Url"] = OhNet.SoapRequest.readStringParameter(result["Url"]);	
		result["ImageUri"] = OhNet.SoapRequest.readStringParameter(result["ImageUri"]);	
	
		if (successFunction){
			successFunction(result);
		}
	}, function(message, transport) {
		if (errorFunction) {errorFunction(message, transport);}
	});
}


/**
* A service action to Model
* @method Model
* @param {Function} successFunction The function that is executed when the action has completed successfully
* @param {Function} errorFunction The function that is executed when the action has cause an error
*/
CpProxyAvOpenhomeOrgMediaServer1.prototype.Model = function(successFunction, errorFunction){	
	var request = new OhNet.SoapRequest("Model", this.url, this.domain, this.type, this.version);		
    request.send(function(result){
		result["Name"] = OhNet.SoapRequest.readStringParameter(result["Name"]);	
		result["Info"] = OhNet.SoapRequest.readStringParameter(result["Info"]);	
		result["Url"] = OhNet.SoapRequest.readStringParameter(result["Url"]);	
		result["ImageUri"] = OhNet.SoapRequest.readStringParameter(result["ImageUri"]);	
	
		if (successFunction){
			successFunction(result);
		}
	}, function(message, transport) {
		if (errorFunction) {errorFunction(message, transport);}
	});
}


/**
* A service action to Product
* @method Product
* @param {Function} successFunction The function that is executed when the action has completed successfully
* @param {Function} errorFunction The function that is executed when the action has cause an error
*/
CpProxyAvOpenhomeOrgMediaServer1.prototype.Product = function(successFunction, errorFunction){	
	var request = new OhNet.SoapRequest("Product", this.url, this.domain, this.type, this.version);		
    request.send(function(result){
		result["Name"] = OhNet.SoapRequest.readStringParameter(result["Name"]);	
		result["Info"] = OhNet.SoapRequest.readStringParameter(result["Info"]);	
		result["Url"] = OhNet.SoapRequest.readStringParameter(result["Url"]);	
		result["ImageUri"] = OhNet.SoapRequest.readStringParameter(result["ImageUri"]);	
	
		if (successFunction){
			successFunction(result);
		}
	}, function(message, transport) {
		if (errorFunction) {errorFunction(message, transport);}
	});
}


/**
* A service action to Attributes
* @method Attributes
* @param {Function} successFunction The function that is executed when the action has completed successfully
* @param {Function} errorFunction The function that is executed when the action has cause an error
*/
CpProxyAvOpenhomeOrgMediaServer1.prototype.Attributes = function(successFunction, errorFunction){	
	var request = new OhNet.SoapRequest("Attributes", this.url, this.domain, this.type, this.version);		
    request.send(function(result){
		result["Value"] = OhNet.SoapRequest.readStringParameter(result["Value"]);	
	
		if (successFunction){
			successFunction(result);
		}
	}, function(message, transport) {
		if (errorFunction) {errorFunction(message, transport);}
	});
}


/**
* A service action to Query
* @method Query
* @param {String} Request An action parameter
* @param {Function} successFunction The function that is executed when the action has completed successfully
* @param {Function} errorFunction The function that is executed when the action has cause an error
*/
CpProxyAvOpenhomeOrgMediaServer1.prototype.Query = function(Request, successFunction, errorFunction){	
	var request = new OhNet.SoapRequest("Query", this.url, this.domain, this.type, this.version);		
    request.writeStringParameter("Request", Request);
    request.send(function(result){
		result["Result"] = OhNet.SoapRequest.readStringParameter(result["Result"]);	
	
		if (successFunction){
			successFunction(result);
		}
	}, function(message, transport) {
		if (errorFunction) {errorFunction(message, transport);}
	});
}


