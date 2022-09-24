package client;

import java.io.Serializable;

public class AlertNotification implements Serializable
{
    private final int componentId;
    private final int criticality;

    public AlertNotification(int componentId, int criticality)
    {
        this.componentId = componentId;
        this.criticality = criticality;
    }

    public int getComponentId() {
        return componentId;
    }

    public int getCriticality() {
        return criticality;
    }
}
